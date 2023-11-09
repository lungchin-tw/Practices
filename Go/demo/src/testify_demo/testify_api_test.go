package main

import (
	"errors"
	"fmt"
	"testing"

	"github.com/stretchr/testify/suite"
)

type APITestSuite struct {
	suite.Suite
}

func (s *APITestSuite) SetupSuite() {
	fmt.Println("APITestSuite::SetupSuite")
	const (
		testFatal = true
		testNilf  = true
	)

	err := errors.New("SetupSuite Error")
	if testFatal {
		s.T().Fatal(err)
	}

	if testNilf {
		s.Nilf(err, "error message %s", "formatted")
	}
}

func (s *APITestSuite) TearDownSuite() {
	fmt.Println("APITestSuite::TearDownSuite")
}

func (s *APITestSuite) SetupTest() {
	fmt.Println("APITestSuite::SetupTest")
}

func (s *APITestSuite) TearDownTest() {
	fmt.Println("APITestSuite::TearDownTest")
}

func (s *APITestSuite) TestNil() {
	fmt.Println("APITestSuite::TestNil")
	err := errors.New("TestNil")
	s.Nil(err)
}

func (s *APITestSuite) TestNilf() {
	fmt.Println("APITestSuite::TestNil")
	err := errors.New("TestNilf")
	s.Nilf(err, "error message %s", "formatted")
}

func TestAPI(t *testing.T) {
	suite.Run(t, new(APITestSuite))
}
