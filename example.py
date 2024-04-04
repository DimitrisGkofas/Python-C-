# my_code.py
import ctypes

# Load the shared library
my_code_lib = ctypes.CDLL('./my_code.dll')

# Define the function prototype
greet = my_code_lib.greet
greet.argtypes = [ctypes.c_char_p]

# Call the function
greet(b"John")
