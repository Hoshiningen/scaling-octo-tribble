# scaling-octo-tribble

# configure the visual studio project

Simple (tested) way:
  1. Run move_files.bat to move the preconfigured VS files to the correct location.
  2. Run visual studio by clicking the .sln file, then build and run the project!
 
 One flaw is that this method exposes the .vs file to be non-hidden.
  
Best way:
  1. Run visual studio on the .sln file first; this will not work, but it will correctly make the .vs folder hidden and generate other files.
  2. Run move_files.bat.
  3. Run visual studio by clicking the .sln file, then build and run the project!
