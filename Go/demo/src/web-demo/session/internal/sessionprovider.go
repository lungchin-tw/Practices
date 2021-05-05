package internal

import (
	"container/list"
	"fmt"
	"sync"
	"time"
)

var SessionProviders map[string]ISessionProvider = make(map[string]ISessionProvider)

type SessionStore struct {
	provider     ISessionProvider
	sid          string                      // unique session id
	timeAccessed time.Time                   // last access time
	pairs        map[interface{}]interface{} // session values
}

func (this *SessionStore) Set(key, value interface{}) error {
	this.pairs[key] = value
	this.provider.SessionUpdate(this.sid)
	return nil
}

func (this *SessionStore) Get(key interface{}) interface{} {
	this.provider.SessionUpdate(this.sid)
	if v, ok := this.pairs[key]; ok {
		return v
	}

	return nil
}

func (this *SessionStore) Delete(key interface{}) error {
	delete(this.pairs, key)
	this.provider.SessionUpdate(this.sid)
	return nil
}

func (this *SessionStore) SessionID() string {
	return this.sid
}

func (this *SessionStore) Expired(maxLifeTime int64) bool {
	return (this.timeAccessed.Unix() + maxLifeTime) < time.Now().Unix()
}

func (this *SessionStore) RenewAccessTime() {
	this.timeAccessed = time.Now()
}

func NewSessionProvider() *SessionProvider {
	return &SessionProvider{
		sessions: make(map[string]*list.Element),
		list:     list.New(),
	}
}

type SessionProvider struct {
	mu       sync.Mutex
	sessions map[string]*list.Element
	list     *list.List
}

func (this *SessionProvider) SessionInit(sid string) (ISession, error) {
	this.mu.Lock()
	defer this.mu.Unlock()
	session := &SessionStore{
		provider:     this,
		sid:          sid,
		timeAccessed: time.Now(),
		pairs:        make(map[interface{}]interface{}),
	}

	this.sessions[sid] = this.list.PushBack(session)
	return session, nil
}

func (this *SessionProvider) SessionRead(sid string) (ISession, error) {
	if v, ok := this.sessions[sid]; ok {
		return v.Value.(ISession), nil
	} else {
		return this.SessionInit(sid)
	}
}

func (this *SessionProvider) SessionDestroy(sid string) error {
	if v, ok := this.sessions[sid]; ok {
		delete(this.sessions, sid)
		this.list.Remove(v)
	}

	return nil
}

func (this *SessionProvider) SessionGC(maxLifeTime int64) {
	this.mu.Lock()
	defer this.mu.Unlock()

	for {
		elem := this.list.Back()
		if elem == nil {
			break
		}

		session := elem.Value.(ISession)
		if session.Expired(maxLifeTime) {
			this.list.Remove(elem)
			delete(this.sessions, session.SessionID())
			fmt.Println("[SessionGC], Deleted:", session.SessionID())
		} else {
			break
		}
	}
}

func (this *SessionProvider) SessionUpdate(sid string) {
	this.mu.Lock()
	defer this.mu.Unlock()

	if v, ok := this.sessions[sid]; ok {
		v.Value.(ISession).RenewAccessTime()
		this.list.MoveToFront(v)
	}
}
