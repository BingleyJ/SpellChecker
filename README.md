John Bingley spell checker.

Spell checker using c++ set.
Compare any text file against dictionary.txt

Just enter the filename. It must be in project root with dictionary.txt.
Soon you will be getting a huge list of misspelled words. 

The program edits every string and strips garbage letters.
line 53 : char badchars[] = ".,}{[]();:!@#$%^&*/?><=-+_'12345567890\""; <- bad letters
then compares with the pre loaded dictionary file. 
Time is recorded on dictionary load time as well as search times. 

