# Employee Management System

This is a simple Employee Management System implemented in C, allowing users to manage employee data. The program allows users to add, view, remove, and search for employee records. It also provides functionality to sort the employee IDs.

## Features

1. **Add Employee**: Users can add multiple employee records, including their name, ID, and password.

2. **View Employee Details**: The program displays a list of all employees with their respective names, IDs, and passwords.

3. **Remove Employee**: Users can remove an employee from the list by providing their ID.

4. **Sort Employee IDs**: The system sorts employee IDs in ascending order.

5. **Search Employee**: Users can search for an employee by providing their name.

6. **Data Persistence**: Employee data is saved to a file (`employee_data.txt`) when the program exits and loaded back when the program starts, ensuring data persistence across sessions.

## How to Use

1. Upon running the program, it will load previously saved employee data from the `employee_data.txt` file.

2. Users are presented with a menu to select their desired operation:

   - Press 1 to view all employee details.
   - Press 2 to add a new employee.
   - Press 3 to remove an employee by their ID.
   - Press 4 to sort employee IDs.
   - Press 5 to search for an employee by name.

3. After performing the desired operation, the program will save the updated employee data to the `employee_data.txt` file before exiting.

## Compilation and Execution

Compile the program using `gcc` or any C compiler:

Run the compiled executable:


## Note

This program is a basic implementation and does not include user authentication or data encryption. It is recommended to add further security features and error handling based on specific requirements.

Feel free to explore and enhance the Employee Management System by adding more features and improving usability to suit your needs.

## Contributors

- [Haris Malik](https://www.malikharis.in/) - Developer.

## License

This project is licensed under the [MIT License](LICENSE). Feel free to use, modify, and distribute the code for personal and commercial purposes. However, remember to include the original license information in any distributions.
