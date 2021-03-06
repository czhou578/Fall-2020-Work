/*
CS 331 Database Design Fall 2020
Java Application for Group 1 - Project 1 "Project 1 International Student Information System"
By:  Colin Zhou, Ruiting Zhang, Samuel Faulkner

-------------------------------------------------------------------------------------------------------------------------------------

Description: Main menu selection #3 database MySql query.
 1. Addition new student information
 2. Addition new course information , 
 3. Addition new department information 
 4. Allows Registration of a student
 
*/

package InternationalStudent;

import java.io.IOException;
import java.sql.Connection;
import java.sql.Date;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.text.SimpleDateFormat;
import java.util.Scanner;

public class Updates {
	public static void updateInterface() throws SQLException {
		try {
			if (askCredentials() == false) { // Authenticates User
				return;
			} else {
				updateInfo();
				returnToMain();
			}

		} catch (SQLException se) {
			System.out.println(se);
		}

	}

	// User verification
	static boolean askCredentials() {
		System.out.println("Enter credentials");
		Scanner input = new Scanner(System.in);
		System.out.print("Enter Username: ");

		String username = input.nextLine();
		System.out.print("Enter password: ");

		String password = input.nextLine();
		if (!username.equals("student") || !password.equals("password")) {
			System.out.println("Incorrect credentials. Try again!");
			return false;
		}
		System.out.println();
		return true;

	}

	// UI for class Main menu option 4
	static void updateInfo() throws SQLException {
		boolean done = false;
		do {
			printOptions();
			System.out.print("Type in your option: ");
			Scanner input = new Scanner(System.in);
			int number = input.nextInt();
			System.out.println();
			switch (number) {
			case 1:
				addStudent();
				break;
			case 2:
				addCourse();
				break;
			case 3:
				addDepartment();
				break;
			case 4:
				registerStudent();
				break;
			case 5:
				done = true;
				break;
			default:
				System.out.println(" Not a valid option ");
			}

		} while (!done);
	}

	static void printOptions() {
		System.out.println("    		Insert New Information"); // printing statements
		System.out.println("--------------------------------------------------\n");
		System.out.println("                  1. Add new student information ");
		System.out.println("                  2. Add new course information ");
		System.out.println("                  3. Add new department information");
		System.out.println("                  4. Register a student");
		System.out.println("                  5. Quit");

	}

	static void addStudent() throws SQLException { // works

		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter Ssn: ");
		int ssn = scanner.nextInt();
		scanner.nextLine();
		System.out.println();

		System.out.print("Enter First Name: ");
		String firstName = scanner.nextLine();
		System.out.println();

		System.out.print("Enter Last Name: ");
		String lastName = scanner.nextLine();
		System.out.println();

		System.out.print("Enter BirthDate With Dashes In-Between (yyyy-mm-dd): ");
		String theDate = scanner.nextLine();
		Date date = java.sql.Date.valueOf(theDate);

		System.out.println();
		System.out.print("Enter gender: ");
		String gender = scanner.nextLine();
		System.out.println();

		System.out.print("Enter Address: ");
		String addr = scanner.nextLine();
		System.out.println();

		System.out.print("Enter Enrollment Date With Dashes In-Between (yyyy-mm-dd): ");
		String enrollDate = scanner.nextLine();
		Date registerDate = java.sql.Date.valueOf(enrollDate);
		System.out.println();

		System.out.print("Enter Type: ");
		String type = scanner.nextLine();
		System.out.println();

		System.out.print("Enter Visa Type: ");
		String visaType = scanner.nextLine();
		System.out.println();

		System.out.print("Enter Visa Starting Date (yyyy-mm-dd): ");
		String visaStart = scanner.nextLine();
		Date startDate = java.sql.Date.valueOf(visaStart);
		System.out.println();

		System.out.print("Enter Visa Ending Date (yyyy-mm-dd): ");
		String visaEnd = scanner.nextLine();
		Date endVisa = java.sql.Date.valueOf(visaEnd);
		System.out.println();

		String query = "INSERT INTO student (Ssn, first_name, last_name, birthdate, gender, addr, enroll_date, type, visa_type, visa_starting_date, "
				+ "visa_expiration_date)" + " VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

		PreparedStatement stmt = InternationalStudentMain.conn.prepareStatement(query);
		stmt.setInt(1, ssn);
		stmt.setString(2, firstName);
		stmt.setString(3, lastName);
		stmt.setDate(4, date);
		stmt.setString(5, gender);
		stmt.setString(6, addr);
		stmt.setDate(7, registerDate);
		stmt.setString(8, type);
		stmt.setString(9, visaType);
		stmt.setDate(10, startDate);
		stmt.setDate(11, endVisa);
		stmt.executeUpdate();
		System.out.println();
		System.out.println("Completed successfully!");

	}

	static void addCourse() throws SQLException { // works
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter Course_ID: ");
		int courseID = scanner.nextInt();
		scanner.nextLine();
		System.out.println();

		System.out.print("Enter Course Name: ");
		String courseName = scanner.nextLine();
		System.out.println();

		System.out.print("Enter Credits: ");
		String credits = scanner.nextLine();
		System.out.println();

		System.out.print("Enter Department_ID: ");
		int deptID = scanner.nextInt();
		System.out.println();

		String query = "Insert into course(course_id, course_name, credits, department_id) values" + "(?, ?, ?, ?)";

		PreparedStatement stmt = InternationalStudentMain.conn.prepareStatement(query);
		stmt.setInt(1, courseID);
		stmt.setString(2, courseName);
		stmt.setString(3, credits);
		stmt.setInt(4, deptID);

		stmt.executeUpdate();
		System.out.println();
		System.out.println("Completed successfully!");

	}

	static void addDepartment() throws SQLException { // works
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter Department_ID: ");
		int deptID = scanner.nextInt();
		scanner.nextLine();
		System.out.println();

		System.out.print("Enter Department_Name: ");
		String deptName = scanner.nextLine();
		System.out.println();

		System.out.print("Enter Department_Addr: ");
		String deptaddr = scanner.nextLine();
		System.out.println();

		System.out.print("Enter Head_Name: ");
		String headName = scanner.nextLine();
		System.out.println();

		System.out.print("Enter Head_Addr: ");
		String headAddr = scanner.nextLine();
		System.out.println();

		System.out.print("Enter College_ID: ");
		int collegeID = scanner.nextInt();
		scanner.nextLine();
		System.out.println();

		String query = "insert into department(department_id, department_name, department_addr, head_name, "
				+ "head_addr, college_id) values (?, ?, ?, ?, ?, ?)";

		PreparedStatement stmt = InternationalStudentMain.conn.prepareStatement(query);
		stmt.setInt(1, deptID);
		stmt.setString(2, deptName);
		stmt.setString(3, deptaddr);
		stmt.setString(4, headName);
		stmt.setString(5, headAddr);
		stmt.setInt(6, collegeID);

		stmt.executeUpdate();
		System.out.println();
		System.out.println("Completed successfully!");
	}

	static void registerStudent() throws SQLException {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter student Ssn: ");
		int ssn = scanner.nextInt();
		scanner.nextLine();
		System.out.println();

		System.out.print("Enter Course ID: ");
		int courseID = scanner.nextInt();
		scanner.nextLine();
		System.out.println();

		System.out.print("Enter Quarter: ");
		String courseQuarter = scanner.nextLine();
		System.out.println();

		String query = "insert into student_has_course(student_Ssn, course_course_id, course_quarter) values"
				+ "(?, ?, ?)";

		PreparedStatement stmt = InternationalStudentMain.conn.prepareStatement(query);

		stmt.setInt(1, ssn);
		stmt.setInt(2, courseID);
		stmt.setString(3, courseQuarter);

		stmt.executeUpdate();
		System.out.println();

		ResultSet rset;

		String query2 = "select student_Ssn, SUM(credits) from student_has_course join course on course_course_id = course_id group by student_Ssn";
		PreparedStatement stmt2 = InternationalStudentMain.conn.prepareStatement(query2);

		rset = stmt2.executeQuery();

		while (rset.next()) {
			int studentSsn = rset.getInt(1);
			int totalCredits = rset.getInt(2);
			if (totalCredits < 12) {
				System.out.println("Not enough credits! Please add more classes for student Ssn: " + studentSsn);
			}
		}

		System.out.println();
	}

	// Return to Main Menu escape
	private static void returnToMain() {
		boolean done = false;
		do {
			System.out.println();
			System.out.println("Enter 1 to return to main interface or 2 to cancel: ");
			System.out.println();
			Scanner input = new Scanner(System.in);
			int number = input.nextInt();

			switch (number) {
			case 1:
				done = true;
				break;
			case 2:
				try {
					updateInfo();
				} catch (SQLException se) {
					System.out.println(se);
				}
				break;
			default:
				System.out.println(" Not a valid option ");
			}

		} while (!done);
	}
}
