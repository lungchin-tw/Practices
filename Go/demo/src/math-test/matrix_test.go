package mathtest

import "testing"

/*
x  + 2y + z = 2
3x + 8y + z = 12
     4y + z = 2
*/

func TestLinearAlgebra_Matrix(t *testing.T) {
	// [row][col]
	a := [][]int{
		{1, 2, 1}, // row 0
		{3, 8, 1}, // row 1
		{0, 4, 1}, // row 2
	}

	t.Log("a[1][2]", a[1][2])
	t.Log("a[2][1]", a[2][1])

	c := [][]int{
		{2},
		{12},
		{2},
	}

	t.Log("c[1][0]", c[1][0])
	t.Log("c[2][0]", c[2][0])
}
