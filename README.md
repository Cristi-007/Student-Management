# Student-Management
This is my first project in C. This program processes data about students and it was created to execute the following requirements:

1. In the program, access is allowed through authentication

    1.1 Authentication is divided into 2 levels (user, admin).
  
    1.2 The user structure will have the following elements: password, type (user = 0 / admin = 1), status (active = 1 / inactive = 0), id.
  
    1.3 An array of CONT structures will be declared in which the structures with user and admin values will be store.

2. The system will process some "students" information. The structure of a STUD structure:

    • name
    
    •	surname
  
    • age
  
    • IDNP
  
    • group
  
    • user_ID_insert (user who created the record)
  
    • active/inactive


3. The program must be formatted as a menu:

    3.1. Administrator menu: 
      - User Management --> Insert user, Edit user, Show user, Find user (based on ID or ....).
      - Student Register (check IDNP).
      - Show Student (via pagination) - active/inactive/all.
      - Student Search --> by name/surname, by IDNP, by group.
      - Student editing - SubMenu - yes DONE
      - Reports:
        + List of students by age (number, group, name, surname, age) information type active/inactive/ALL
        + List of students by group (number, group, name, surname, IDNP) information type active/inactive/ALL
        + List of students (number, group, name, surname, IDNP) information type active/inactive/ALL DONE
        + Statistics
        
  3.2. User menu (only active students):    
      - Search Student.   
      - Show Student.   
      - Edit Student.   
      - Reports.   
    
The information (structure or all structures) must be saved in separate files. Loading the information into the program must be done both at the menu level (admin) 
and at the automated level for the user and admin.


The program must collect statistics per user
The statistics will be stored at the structure level in the file, the structure has the following fields: 
  - structure name: statistics
    - User ID.
    - Number of accesses (authentications).
    - The number of inserted users.
    - The number of inserted students.
    - The number of edited students.
    - Number of disabled student.
