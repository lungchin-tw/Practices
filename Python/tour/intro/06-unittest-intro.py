from arithmetic import max
import unittest


# Try: python -m unittest -v 06-unittest-intro.py

class TestArithmetic(unittest.TestCase):
    def test_max_int(self):
        self.assertEqual(max(1,29, -10), 29)

    def test_max_zero_arg(self):
        with self.assertRaises(Exception):
            max()

