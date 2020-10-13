package main

import (
	"fmt"
	"math/rand"
	"time"
)

const (
	MAX_SCENE_TYPE = 3
	MAX_TEAM_TYPE  = 3
)

var ShutdownChan chan bool = make(chan bool)
var MatchmakingChan *TMatchmakingChan
var GlobalPlayerUniqueID uint64

func init() {
	MatchmakingChan = &TMatchmakingChan{
		Chan:         make(chan *TPlayer, 100),
		TotalNumChan: 1,
	}

	MatchmakingChan.ScenenChanArray = make([]*TSceneChan, MAX_SCENE_TYPE)
	for scene_type := range MatchmakingChan.ScenenChanArray {
		MatchmakingChan.TotalNumChan++
		scenechan := &TSceneChan{
			SceneType: scene_type,
			Chan:      make(chan *TPlayer, 10),
		}

		scenechan.TeamChanArray = make([]*TTeamChan, MAX_TEAM_TYPE)
		for team_type := range scenechan.TeamChanArray {
			MatchmakingChan.TotalNumChan++
			scenechan.TeamChanArray[team_type] = &TTeamChan{
				TeamType: team_type,
				Chan:     make(chan *TPlayer, 10),
			}
		}

		MatchmakingChan.ScenenChanArray[scene_type] = scenechan
	}
}

func main() {
	rand.Seed(time.Now().UTC().UnixNano())

	go func() {
		start := time.Now()

		for {
			default_counter := 0

			select {
			case player := <-MatchmakingChan.Chan:
				MatchmakingChan.Do(player)
			default:
				default_counter++
			}

			for _, scene := range MatchmakingChan.ScenenChanArray {
				select {
				case player := <-scene.Chan:
					scene.Do(player)
				default:
					default_counter++
				}

				for _, team := range scene.TeamChanArray {
					select {
					case player := <-team.Chan:
						team.Do(player)
					default:
						default_counter++
					}
				}
			}

			if default_counter >= MatchmakingChan.TotalNumChan {
				fmt.Printf("After Matchmaking, Elapse:%v ms, Result=%+v\n", time.Since(start).Milliseconds(), MatchmakingChan)
				fmt.Println("After Matchmaking, Sleep 3 sec")
				time.Sleep(time.Second * 3)
				start = time.Now()
			}
		}

	}()

	go func() {
		for {
			num := rand.Intn(50) + rand.Intn(50)
			MatchmakingChan.EstTotalNumPlayer += num
			fmt.Println("Total Generated Num Player:", MatchmakingChan.EstTotalNumPlayer)

			for i := 0; i < num; i++ {
				GlobalPlayerUniqueID++
				MatchmakingChan.Chan <- &TPlayer{
					ID:        GlobalPlayerUniqueID,
					SceneType: rand.Intn(MAX_SCENE_TYPE),
					TeamType:  rand.Intn(MAX_TEAM_TYPE),
				}
			}

			sleep := time.Duration(rand.Intn(10)) * time.Second
			fmt.Println("After Genereating Players, Sleep", sleep)
			time.Sleep(sleep)
		}
	}()

	<-ShutdownChan
}
