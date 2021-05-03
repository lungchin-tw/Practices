package test

import (
	"encoding/csv"
	"os"
	"testing"
)

func TestReadingCsv(t *testing.T) {
	record_list := make([][]string, 0)
	file, err := os.Open("input.csv")
	defer file.Close()
	if err != nil {
		t.Fatal(err)
	}

	reader := csv.NewReader(file)
	reader.ReuseRecord = false
	for {
		if record, err := reader.Read(); err == nil {
			record_list = append(record_list, record)
			t.Logf("Record #%v: %#v", len(record_list), record)
		} else {
			break
		}
	}
}

func TestWritingCsv(t *testing.T) {
	record_list := [][]string{
		{"year", "name"},
		{"1976", "jacky"},
	}

	file, err := os.Create("output.csv")
	if err != nil {
		t.Fatal(err)
	}

	writer := csv.NewWriter(file)
	for _, record := range record_list {
		if err := writer.Write(record); err != nil {
			t.Fatalf("Writing a record=%#v FAILED!!!:%+v", record, err)
		}
	}

	writer.Flush()
	if err := writer.Error(); err != nil {
		t.Fatal(err)
	}

	defer file.Close()
}
