# UPDATE-Modifying-Existing-Data-in-a-File
The UPDATE operation changes the value of an existing record without affecting the rest of the file. Because file streams work with a position pointer, C++ provides seekg() (get pointer, for reading) and seekp() (put pointer, for writing) to move to a specific byte position in the file, and tellg()/tellp() to report the current position.
