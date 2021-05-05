package session

import (
	"examples/web-demo/session/internal"
	"fmt"
)

var GSessionManager *internal.TSessionManager

func init() {
	RegisterProvider("memory", internal.NewSessionProvider())

	var err error
	if GSessionManager, err = internal.NewSessionManager("memory", "gosessionid", 60); err != nil {
		panic(err)
	} else {
		go GSessionManager.GC()
	}
}

func RegisterProvider(name string, provider internal.ISessionProvider) {
	if provider == nil {
		panic("[RegisterProvider], Provider is nil")
	} else if len(name) < 1 {
		panic("[RegisterProvider], Name is empty")
	} else if _, ok := internal.SessionProviders[name]; ok {
		panic(fmt.Errorf("[RegisterProvider], Provider %v Exists.", name))
	}

	internal.SessionProviders[name] = provider
}
