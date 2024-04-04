import ctypes
import numpy as np

# Load the DLL
my_dll = ctypes.CDLL('./floodfill.dll')

# Define function prototypes
floodFill = my_dll.floodFill
floodFill.argtypes = [
    ctypes.POINTER(ctypes.POINTER(ctypes.c_int)),  # Pointer to pointer for 2D array
    ctypes.c_int,  # M
    ctypes.c_int,  # x
    ctypes.c_int,  # y
    ctypes.c_int,  # currColor
    ctypes.c_int,  # newColor
    ctypes.c_int   # max_depth
]

# Example usage
# Create a 2D array (for demonstration purposes)
M = 128
myScreen = np.ones((M, M), dtype=np.int32)

# Convert the NumPy array to a C-compatible pointer to pointer
myScreen_ptr = (ctypes.POINTER(ctypes.c_int) * M)()
for i in range(M):
    myScreen_ptr[i] = myScreen[i].ctypes.data_as(ctypes.POINTER(ctypes.c_int))

# fps count
import time

# Initialize variables
frame_count = 0
start_time = time.time()

# Main loop
while True:
    # Update frame count
    frame_count += 1

    myScreen[:, :] = np.int32(1)
    # Call the functions
    floodFill(myScreen_ptr, M, 5, 5, 1, 2, 64)
    
    # Display FPS every second
    if time.time() - start_time >= 1:
        fps = frame_count / (time.time() - start_time)
        print("FPS: {:.2f}".format(fps))
        # Reset variables
        frame_count = 0
        start_time = time.time()

    # Simulate processing time (replace this with your actual processing code)
    # time.sleep(0.02)  # Simulating 20ms processing time

# Print the updated array
# print(myScreen)
