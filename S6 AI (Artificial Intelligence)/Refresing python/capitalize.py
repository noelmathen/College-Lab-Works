#write a numpy pgm to capitalize  the first letter , 
#lowercase , uppercase, titlecase of all the elements of the given array

import numpy as np

names = np.array(["my", "nAMe", "is", "NOEL"])
print(f"Original: {names}")
print(f"Capitalize First letter: {np.char.capitalize(names)}")
print(f"Convert to uppercase: {np.char.upper(names)}")
print(f"Convert to lowercase: {np.char.lower(names)}")
print(f"Convert to lowercase: {np.char.title(names)}")