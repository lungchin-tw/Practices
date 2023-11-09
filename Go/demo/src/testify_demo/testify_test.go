package main

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/suite"
)

type CalculatorTestSuite struct {
	suite.Suite
	StartingNumber int
}

func (s *CalculatorTestSuite) SetupSuite() {
	fmt.Println("CalculatorTestSuite::SetupSuite")
	s.StartingNumber = 1
}

func (s *CalculatorTestSuite) TearDownSuite() {
	fmt.Println("CalculatorTestSuite::TearDownSuite")
}

func (s *CalculatorTestSuite) SetupTest() {
	fmt.Println("CalculatorTestSuite::SetupTest")
	s.StartingNumber = 10
}

func (s *CalculatorTestSuite) TearDownTest() {
	fmt.Println("CalculatorTestSuite::TearDownTest")
}

func (s *CalculatorTestSuite) TestAdd() {
	fmt.Println("CalculatorTestSuite::TestAdd")
	s.StartingNumber += 1
	s.Equal(11, s.StartingNumber)
	// s.Equal(1, s.StartingNumber)
}

func (s *CalculatorTestSuite) TestSubtract() {
	fmt.Println("CalculatorTestSuite::TestSubtract")
	s.StartingNumber -= 1
	s.EqualValues(9, s.StartingNumber, "error message %s", "formatted")
	// s.EqualValues(1, s.StartingNumber, "error message %s", "formatted")
}

func TestCalculator(t *testing.T) {
	suite.Run(t, new(CalculatorTestSuite))
}
