package internal

import (
	"crypto/rand"
	"encoding/base64"
	"fmt"
	"net/http"
	"net/url"
	"sync"
)

/*
** NewSessionManager
 */
func NewSessionManager(providerName, cookieName string, maxlifetime int64) (*TSessionManager, error) {
	if provider, ok := SessionProviders[providerName]; !ok {
		return nil, fmt.Errorf("[NewSessionManager], Provider %v Not Exists", providerName)
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
