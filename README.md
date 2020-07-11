# QuickReader
Command line program written in C++ that allows a user to open a .txt file and have the individual words flash on the screen so the reader is not limited to the speed of their eyes.

When speedreading, humans are limited to about 250-300 words per minute due to the movements of our eyes, but if one were to "move the words" instead of us moving our eyes, we can read up to an average of 500 words per minute. This program takes the text from a .txt file and displays each one after another in order in the same spot so the reader does not need to use their eye movement, saving time. An explanation of this function is well explained here: 

[![](http://img.youtube.com/vi/K8dIVNDMA_0/0.jpg)](http://www.youtube.com/watch?v=K8dIVNDMA_0 "")


The program uses a "smart word" detection for timing, so for shorter words like "a, the, who" less time is spent in between displays and for larger words such as "nevertheless, California, however" more time is spent in between displays to help the reader comprehend the text. The program also gives extra display time for words that end in punctuation.
To start reading, simply hold down the shift key and to pause, simply let go of the shift key.
