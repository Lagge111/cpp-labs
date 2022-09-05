// Focus on three aspects: Correctness, Usability, Changeability

/* CORRECTNESS
- The module should not produce incorrect results given any correct input. 
- Incorrect usage should not result in messages printed to terminal.
- If an error occurs due to incorrect usage, it should be reported to the user. 
- Write tests that automatically verifies the correctness of the module, i.e. does not require user input through terminal. SHOULD PROBABLY USE STREAM FLAGS (SLIDES: FUNCTIONS AND STRUCTS, SLIDES 79 - 83)

USABILITY
- Clear naming. 
- Very general function that can work in as many cases as possible.
- Constant (const) timepoints should be possible to use.
- Code should be divided into an implementation file and a header file (reference manual). Document in the code what is important to read for other programmers, and what is unneccesary to read.

CHANGEABILITY
- Should be easy to change the implementation of various functions, i.e. function parameters and return values should be independent of how the code is written. A function get_hour() should return at what hous this timepoint occurs at, regardless of how the timepoint is actually implemented. 
- Implement time struct with three integers: one for hours, one for minutes and one for seconds. 
 */

/* ASSIGNMENT 

- Create a data structure and all the functions that are needed to handle time. 
- Time is defined as three integers in the format HH:MM:SS. 
- The minimal requirements are:
    - Check if time is valid or not. Hours in interval [0,23], minutes and seconds in interval [0,59]. Use is_valid(). 

    - Possibility to get time a string. With two formats; 24-hour clock "14:21:23" and AM/PM clock "02:21:23 am". Result is a string in format HH:MM:SS[ p] where p is either AM or PM. Create function to_string() that returns a string in the format above. There must be an extra parameter to to_string() that determines 24-hour clock format or AM/PM. 

    - Check if time is before or after noon (AM or PM). Use function is_am()

    - Addition with a positive integer N to generate a new time N seconds into the future with operator+. 
*/