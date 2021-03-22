package internal

import (
	"container/list"
	"sync"
)

var SessionProviders map[string]ISessionProvider = make(map[string]ISessionProvider)

type SessionProvider struct {
	mu       sync.Mutex
	sessions map[string]*list.Element
	list     *list.List
}

func (this *SessionProvider) SessionInit(sid string) (ISession, error) {
	this.mu.Lock()
	defer this.mu.Unlock()
	return nil, nil

}

func (this *SessionProvider) SessionRead(sid string) (ISession, error) {
	return nil, nil
}

func (this *SessionProvider) SessionDestroy(sid string) error {
	return nil
}

func (this *SessionProvider) SessionGC(maxLifeTime int64) {

}
