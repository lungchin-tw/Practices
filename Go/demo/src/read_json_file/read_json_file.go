package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
)

type raw_reel_strip_data struct {
	bet_1_2 []string
	bet_3   []string
}

type CurrencyRatio struct {
	USD float32
	EUR float32
	GBP float32
}

type FafafaConf struct {
	NumCols        int               `json:"NumCols"`
	NumRows        int               `json:"NumRows"`
	CoinSizeList   []float32         `json:"CoinSizeList"`
	MultiplierList []int             `json:"MultiplierList"`
	PayTable       [][]int           `json:"PayTable"`
	SymbolList     []string          `json:"SymbolList"`
	ReelStrip      RawReelStripTable `json:"ReelStrip"`
}

type RawReelStripTable struct {
	Bet_1_2 []string `json:"Bet_1_2"`
	Bet_3   []string `json:"Bet_3"`
}

func main() {
	{
		data, err := ioutil.ReadFile("./example.json")

		if err != nil {
			fmt.Println("Error: ", err)
		}

		var json_obj CurrencyRatio
		err = json.Unmarshal(data, &json_obj)
		if err != nil {
			fmt.Println("Error: ", err)
		}

		fmt.Println("CurrencyRatio: ", json_obj)
	}

	{
		data, err := ioutil.ReadFile("./fafafa.json")

		if err != nil {
			fmt.Println("Error: ", err)
		}

		var json_obj FafafaConf
		err = json.Unmarshal(data, &json_obj)
		if err != nil {
			fmt.Println("Error: ", err)
		}

		fmt.Printf("FafafaConf: %+v\n", json_obj)
	}
}
