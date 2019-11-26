package main

import (
	"encoding/csv"
	"fmt"
	"log"
	"os"
)

func main() {

	/*
	** Demo reading a csv file
	 */
	record_list := make([][]string, 0)
	{
		file, err := os.Open("Data Simulation - Sheet1.csv")
		if err != nil {
			fmt.Printf("Read a csv File Failed:%+v\n", err)
			return
		}

		defer file.Close()

		reader := csv.NewReader(file)
		// reader.ReuseRecord = true
		reader.ReuseRecord = false
		counter := 0
		for {
			counter++
			record, err := reader.Read()
			if err != nil {
				fmt.Printf("Read Record %v Failed:%+v\n", counter, err)
				break
			}

			record_list = append(record_list, record)

			fmt.Printf("Record %v: %#v\n", counter, record)
		}
	}

	/*
	** Demo writing a csv file
	 */
	{
		fmt.Printf("RecordList:\n%#v\n", record_list)
		file, err := os.Create("output.csv")
		if err != nil {
			fmt.Printf("Create a csv File Failed:%+v\n", err)
		}

		writer := csv.NewWriter(file)
		for _, record := range record_list {
			if err := writer.Write(record); err != nil {
				fmt.Printf("Writing a record=%#v FAILED!!!:%+v\n", record, err)
				break
			}
		}

		writer.Flush()
		if err := writer.Error(); err != nil {
			log.Fatal(err)
		}

		defer file.Close()
	}
}
