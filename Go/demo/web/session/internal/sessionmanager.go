package internal

import (
	"crypto/rand"
	"encoding/base64"
	"fmt"
	"net/http"
	"net/url"
	"sync"
	"time"
)

/*
** NewSessionManager
 */
func NewSessionManager(providerName, cookieName string, maxlifetime int64) (*TSessionManager, error) {
	if provider, ok := SessionProviders[providerName]; !ok {
		return nil, fmt.Errorf("[NewSessionManager], Provider [%v] Not Exists", providerName)
	} else {
		return &TSessionManager{cookieName: cookieName, provider: provider, maxLifeTime: maxlifetime}, nil
	}
}

// TSessionManager
type TSessionManager struct {
	cookieName  string
	mu          sync.Mutex
	provider    ISessionProvider
	maxLifeTime int64
}

func (this *TSessionManager) genSessionID() string {
	bytes := make([]byte, 32)
	rand.Read(bytes)
	return base64.URLEncoding.EncodeToString(bytes)
}

func (this *TSessionManager) SessionStart(w http.ResponseWriter, r *http.Request) ISession {
	this.mu.Lock()
	defer this.mu.Unlock()
	cookie, err := r.Cookie(this.cookieName)
	if (err != nil) || (len(cookie.Value) < 1) {
		sid := this.genSessionID()
		session, _ := this.provider.SessionInit(sid)
		http.SetCookie(w, &http.Cookie{
			Name:     this.cookieName,
			Value:    url.QueryEscape(sid),
			Path:     "/",
			HttpOnly: true,
			MaxAge:   int(this.maxLifeTime),
		})

		return session
	} else {
		sid, _ := url.QueryUnescape(cookie.Value)
		session, _ := this.provider.SessionRead(sid)
		return session
	}
}

func (this *TSessionManager) SessionDestroy(w http.ResponseWriter, r *http.Request) {
	this.mu.Lock()
	defer this.mu.Unlock()

	cookie, err := r.Cookie(this.cookieName)
	if (err != nil) || (len(cookie.Value) < 1) {
		return
	}

	this.provider.SessionDestroy(cookie.Value)
	http.SetCookie(w, &http.Cookie{
		Name:     this.cookieName,
		Path:     "/",
		HttpOnly: true,
		Expires:  time.Now(),
		MaxAge:   -1,
	})
}

func (this *TSessionManager) GC() {
	fmt.Println("TSessionManager:GC,", time.Now().String())
	this.mu.Lock()
	defer this.mu.Unlock()

	this.provider.SessionGC(this.maxLifeTime)
	time.AfterFunc(time.Duration(this.maxLifeTime*int64(time.Second)), func() { this.GC() })
}
