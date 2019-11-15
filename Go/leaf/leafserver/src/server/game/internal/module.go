package internal

import (
	"runtime"
	"server/base"
	"time"

	"github.com/name5566/leaf/log"
	"github.com/name5566/leaf/module"
)

var (
	skeleton = base.NewSkeleton()
	ChanRPC  = skeleton.ChanRPCServer
)

type Module struct {
	*module.Skeleton
}

func (m *Module) OnInit() {
	m.Skeleton = skeleton
	log.Debug("[1]runtime.NumGoroutine: %v", runtime.NumGoroutine())

	var res string
	skeleton.Go(func() {
		time.Sleep(time.Second)
		res = "3"
		log.Debug("[3-1]runtime.NumGoroutine: %v", runtime.NumGoroutine())
	}, func() {
		log.Debug("[3-2]runtime.NumGoroutine: %v, res:%v", runtime.NumGoroutine(), res)
	})

	log.Debug("[2]runtime.NumGoroutine: %v", runtime.NumGoroutine())

	skeleton.AfterFunc(time.Second, func() {
		log.Debug("skeleton.AfterFunc: %s", time.Now())
	})
}

func (m *Module) OnDestroy() {

}
