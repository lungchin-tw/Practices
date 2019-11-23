package main

import "encoding/csv"

import "os"

import "fmt"

func main() {

	/*
	** Demo reading a csv file
	 */
	{
		file, err := os.Open("Data Simulation - Sheet1.csv")
		if err != nil {
			fmt.Printf("Read a csv File Failed:%+v\n", err)
			return
		}

		defer file.Close()

		reader := csv.NewReader(file)
		reader.ReuseRecord = true
		counter := 0
		for {
			counter++
			record, err := reader.Read()
			if err != nil {
				fmt.Printf("Read Record %v Failed:%+v\n", counter, err)
				break
			}

			fmt.Printf("Record %v: %#v\n", counter, record)
		}
	}

	/*
	** Demo writing a csv file
	 */
	{
		file, err := os.Create("output.csv")
		if err != nil {
			fmt.Printf("Create a csv File Failed:%+v\n", err)
		}

		writer := csv.NewWriter(file)
		writer.Flush()

		defer file.Close()
	}
}
