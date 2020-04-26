# Secure-Programming-with-C
Safe and secure code for a e-voting system software

The applied CERT rules and recommendations are as follows - 
1. DCL04-C Not more than 1 var per declaration.
2. INT01-C use size_t to represent the size of an object
3. EXP20-C explicitly check if condition.
4. EXP31-C. Do not modify constant values
5. STR05-A. Prefer making string literals const-qualified
	//any attempt made to change these leads to an error
6. STR30-C. Do not attempt to modify string literals
7. //MEM02-A. Do not cast the return value from malloc()
8. MEM03-A. Clear sensitive information stored in dynamic memory prior to
						//deallocation
						//at the end of use of ptr we need to free it ie deallocate it
9. //MEM31-C. Free dynamically allocated memory exactly once
10. //MEM34-C. Only free memory allocated dynamically
11.//MEM01-A. Set pointers to dynamically allocated memory to NULL after they
						//are released
12. //MEM31-C. Free dynamically allocated memory exactly once
						//we need to do this
13. //FIO06-A. Create files with appropriate access permissions
14. //FIO11-A. Take care when specifying the mode parameter of fopen()
15. //PRE08-C. Guarantee that header file names are unique.
16. //DCL07-C.Include the appropriate type information in function declarators. 
17. //DCL05-A. Use typedefs to improve code readability
18. //MSC00-A. Compile cleanly at high warning levels 							??????
19. //DCL06-A. Use meaningful symbolic constants to represent literal values in program logic
20. //ARR31-C. Use consistent array notation across all source files
21. //FIO40-C. Reset strings on fgets() failure
//fn that creates number of files equal to number of candidates 					??????
22.//MSC07-A. Detect and remove dead code
23. //MSC13-A. Detect and remove unused values
24. //MSC12-A. Detect and remove code that has no effect

//fn to delete illegal vote
25. //MSC04-A. Use comments consistently and in a readable fashion
26. //DCL32-C. Guarantee identifiers are unique
27. /FIO31-C. Do not simultaneously open the same file multiple times
28. //FIO46-C. Do not access a closed file
29. STR31-C enough space for char data 
	                       // and null terminator.

30. //DCL03-A. Place const as the rightmost declaration specifier
31. //DCL01-A. Do not reuse variable names in sub-scopes
32. //FIO31-C. Do not simultaneously open the same file multiple times. 
33. FIO35-C. Use feof() and ferror() to detect end-of-file and file errors
