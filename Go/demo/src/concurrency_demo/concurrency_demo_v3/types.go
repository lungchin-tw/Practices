package main

import "fmt"

type TPlayer struct {
	ID        uint64
	SceneType int
	TeamType  int
}

type TTeamChan struct {
	TeamType       int
	TotalNumPlayer int
	Chan           chan *TPlayer
}

func (this *TTeamChan) Do(player *TPlayer) {
	this.TotalNumPlayer++
	fmt.Printf("[TeamChan(%v)], %v\n", this.TeamType, *player)
}

func (this *TTeamChan) String() string {
	return fmt.Sprintf(
		"{TeamType:%v, TotalNumPlayer:%v}",
		this.TeamType,
		this.TotalNumPlayer,
	)
}

type TSceneChan struct {
	SceneType      int
	TotalNumPlayer int
	Chan           chan *TPlayer
	TeamChanArray  []*TTeamChan
}

func (this *TSceneChan) String() string {
	return fmt.Sprintf(
		"{SceneType:%v, TotalNumPlayer:%v}",
		this.SceneType,
		this.TotalNumPlayer,
	)
}

func (this *TSceneChan) Do(player *TPlayer) {
	this.TotalNumPlayer++
	this.TeamChanArray[player.TeamType].Chan <- player
	fmt.Printf("[SceneChan(%v)], %v\n", this.SceneType, *player)
}

type TMatchmakingChan struct {
	CurNumPlayer      int
	EstTotalNumPlayer int
	Chan              chan *TPlayer
	ScenenChanArray   []*TSceneChan
	TotalNumChan      int
}

func (this *TMatchmakingChan) String() string {
	return fmt.Sprintf(
		"{NumPlayer:(%v/%v), Scene:%+v}",
		this.CurNumPlayer,
		this.EstTotalNumPlayer,
		this.ScenenChanArray,
	)
}

func (this *TMatchmakingChan) Do(player *TPlayer) {
	this.CurNumPlayer++
	this.ScenenChanArray[player.SceneType].Chan <- player
	fmt.Printf("[MatchmakingChan], %v/%v, %v\n", this.CurNumPlayer, this.EstTotalNumPlayer, *player)
}
