package internal

type ISession interface {
	Set(key, value interface{}) error
	Get(key interface{}) interface{}
	Delete(key interface{}) error
	SessionID() string
}

// ISessionProvider
type ISessionProvider interface {
	SessionInit(sid string) (ISession, error)
	SessionRead(sid string) (ISession, error)
	SessionDestroy(sid string) error
	SessionGC(maxLifeTime int64)
}
