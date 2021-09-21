/*

CS 331 Database Design Fall 2020
Java Application for Group 1 - Project 1 "Project 1 International Student Information System"
By:  Colin Zhou, Ruiting Zhang, Samuel Faulkner

---------------------------------------------------------------------------------------------------------------------
Description: Main menu selection #1 database MySql query. 
menu option 1. Academic Information 
	sub-menu option 1. Educational history 
					- returns query of (school , degree , gpa) of input 'student' Ssn#.
	sub-menu option 2. Student Information. 
					- returns query of (Ssn , Name) of input 'college' name. 											  

menu option 2. Contact Information 
	sub-menu option 1. Student Contact Information
					- returns query of (Ssn , Name , Address , Major Department , College) of input 'student' Ssn#.
	sub-menu option 2. Student Country of Origin
					- returns query of (Ssn , Name ,  Address) of input 'country of origin'.
	sub-menu option 3. Working Student Contact Information	
					- returns query of (Name , Address , Hours worked weekly) of all undergrad students.
									 
menu option 3. Visa Status
	sub-menu option 1. Visa Status Report
					- returns query of (Visa Type , Start date , Expiration Date) of input 'student' Ssn#.
	sub-menu option 2. F-1 visa
					- returns query of (Ssn , Name , Nationality) of all students with type F1 visa.
*/

package InternationalStudent;

import java.io.IOException;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.io.*;
import java.util.*;

public class CurrentStudent {

	Connection conn = null;

	public static void currentStudentInterface() throws SQLException {
		try {
			if (askCredentials() == false) { // Authenticates User
				return;
			} else {
				currentStudentMenu();
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

	// UI for class Main menu option 1
	static void currentStudentMenu() throws SQLException {
		boolean done = false;
		do {
			printMenu();
			System.out.println();
			System.out.print("Type in your option: ");
			Scanner input = new Scanner(System.in);
			int number = input.nextInt();
			System.out.println();
			switch (number) {
			case 1:
				academentInfo();
				break;
			case 2:
				contactInfo();
				break;
			case 3:
				visaStatus();
				break;
			case 4:
				done = true;
				break;
			}

		} while (!done);
	}

	// option 3 menu
	private static void visaStatus() {
		boolean done = false;
		do {
			printMenu3();
			System.out.println();
			System.out.print("Type in your option: ");
			Scanner input = new Scanner(System.in);
			int number = input.nextInt();
			System.out.println();
			switch (number) {
			case 1:
				visaStatusReport();
				break;
			case 2:
				f1visa();
				break;
			case 3:
				done = true;
				break;
			}

		} while (!done);

	}

	// returns query of (Visa Type , Start date , Expiration Date) of input
	// 'student' Ssn#.
	private static void visaStatusReport() {
		try {
			System.out.print("Enter Student Ssn (#########): ");
			System.out.flush();
			String dnum = readLine();
			System.out.println();

			String query = "SELECT * FROM student WHERE Ssn Like ?";
			PreparedStatement prestmt = InternationalStudentMain.conn.prepareStatement(query);

			prestmt.setString(1, dnum);

			ResultSet rset = prestmt.executeQuery();

			System.out.println("    Visa Status Report for Student: " + dnum);
			System.out.println("--------------------------------------------------\n");
			System.out.println("Visa Type   Start date   Expiration Date");

			while (rset.next()) {
				String a = rset.getString("visa_type");
				String b = rset.getString("visa_starting_date");
				String c = rset.getString("visa_expiration_date");
				System.out.println("   " + a + "        " + b + "    " + c);
			}

		} catch (SQLException ex) {
			System.out.println(ex);
		}
		System.out.println();
	}

	// returns query of (Ssn , Name , Nationality) of all students with type F1
	// visa.
	private static void f1visa() {
		try {
			Statement stmt = InternationalStudentMain.conn.createStatement();
			String query = "SELECT * FROM student INNER JOIN student_origin_country ON student.Ssn=student_origin_country.student_Ssn where visa_type = 'F1'";
			ResultSet rset = stmt.executeQuery(query);

			System.out.println("              F-1 Visa");
			System.out.println("--------------------------------------------------\n");
			System.out.println("   Ssn         Name         Nationality");

			while (rset.next()) {
				int Ssn = rset.getInt("Ssn");
				String fname = rset.getString("first_name");
				String lname = rset.getString("last_name");
				String country = rset.getString("country_name");
				System.out.println(Ssn + "    " + fname + " " + lname + "       " + country);
			}

		} catch (SQLException ex) {
			System.out.println(ex);
		}

		System.out.println();
	}

	private static void contactInfo() {
		boolean done = false;
		do {
			printMenu2();
			System.out.println();
			System.out.print("Type in your option: ");
			Scanner input = new Scanner(System.in);
			int number = input.nextInt();
			System.out.println();
			switch (number) {
			case 1:
				studentContactInfo();
				break;
			case 2:
				studentCountryofOrigin();
				break;
			case 3:
				workingStudentContactInfo();
				break;
			case 4:
				done = true;
				break;
			default:
				System.out.println(" Not a valid option ");
			}

		} while (!done);

	}

	// returns query of (Ssn , Name , Address , Major Department , College) of input
	// 'student' Ssn#.
	private static void studentContactInfo() {
		try {
			System.out.print("Enter Student Ssn (#########): ");
			System.out.flush();
			String dnum = readLine();
			System.out.println();

			String query = "SELECT * FROM student \r\n" + "INNER JOIN student_belong_department \r\n"
					+ "ON student.Ssn=student_belong_department.student_Ssn \r\n" + "INNER JOIN department \r\n"
					+ "ON student_belong_department.department_id=department.department_id\r\n"
					+ "INNER JOIN college \r\n" + "ON department.college_id=college.college_id\r\n"
					+ "where Ssn LIKE ?";

			PreparedStatement prestmt = InternationalStudentMain.conn.prepareStatement(query);

			prestmt.setString(1, dnum);

			ResultSet rset = prestmt.executeQuery();

			System.out.println("                         Student Contact Information");
			System.out.println("-----------------------------------------------------------------------------------\n");
			System.out.println("   Ssn         Name         Address               Major Department          College");

			while (rset.next()) {
				int Ssn = rset.getInt("Ssn");
				String fname = rset.getString("first_name");
				String lname = rset.getString("last_name");
				String address = rset.getString("addr");
				String department = rset.getString("department_name");
				String college = rset.getString("college_name");
				System.out.println(Ssn + "    " + fname + " " + lname + "    " + address + "       " + department
						+ "          " + college);
			}

		} catch (SQLException ex) {
			System.out.println(ex);
		}

	}

	// returns query of (Ssn , Name , Address) of input 'country of origin'
	private static void studentCountryofOrigin() {
		try {
			System.out.print("Enter Country: ");
			System.out.flush();
			String dnum = readLine();
			dnum.toLowerCase();
			System.out.println();

			String query = "SELECT * FROM student \r\n" + "INNER JOIN student_origin_country \r\n"
					+ "ON student.Ssn=student_origin_country.student_Ssn \r\n" + "where country_name Like ?";

			PreparedStatement prestmt = InternationalStudentMain.conn.prepareStatement(query);

			prestmt.setString(1, dnum);

			ResultSet rset = prestmt.executeQuery();

			System.out.println("    Student Country of Origin" + dnum);
			System.out.println("--------------------------------------------------\n");
			System.out.println("   Ssn           Name              Address ");

			while (rset.next()) {
				int Ssn = rset.getInt("Ssn");
				String fname = rset.getString("first_name");
				String lname = rset.getString("last_name");
				String address = rset.getString("addr");
				System.out.println(Ssn + "    " + fname + " " + lname + "    " + address);
			}

		} catch (SQLException ex) {
			System.out.println(ex);
		}

	}

	// returns query of (Name , Address , Hours worked weekly) of all undergrad
	// students
	private static void workingStudentContactInfo() {
		try {
			Statement stmt = InternationalStudentMain.conn.createStatement();
			String query = "SELECT * FROM student \r\n" + "INNER JOIN  employed_student\r\n"
					+ "ON student.Ssn=employed_student.student_Ssn \r\n" + "INNER JOIN  job\r\n"
					+ "ON employed_student.job_name=job.job_name";
			ResultSet rset = stmt.executeQuery(query);

			System.out.println("                 Working Student");
			System.out.println("--------------------------------------------------\n");

			while (rset.next()) {
				int Ssn = rset.getInt("Ssn");
				String fname = rset.getString("first_name");
				String lname = rset.getString("last_name");
				String address = rset.getString("addr");
				int hrwork = rset.getInt("job_hours");
				System.out.println("                SSn: " + Ssn);
				System.out.println("               Name: " + fname + " " + lname);
				System.out.println("            Address: " + address);
				System.out.println("Hours worked weekly: " + hrwork);
				System.out.println();
			}

		} catch (SQLException ex) {
			System.out.println(ex);
		}

	}

	private static void academentInfo() {
		boolean done = false;
		do {
			printMenu1();
			System.out.println();
			System.out.print("Type in your option: ");
			Scanner input = new Scanner(System.in);
			int number = input.nextInt();
			System.out.println();
			switch (number) {
			case 1:
				educationalHistory();
				break;
			case 2:
				studentInfo();
				break;
			case 3:
				done = true;
				break;
			}

		} while (!done);

	}

//returns query of (Ssn , Name) of input 'college' name.
	private static void studentInfo() {

		String dnum = "";
		boolean done = false;
		do {
			printMenu4();
			System.out.println();
			System.out.print("Type in your option: ");
			Scanner input = new Scanner(System.in);
			int number = input.nextInt();
			System.out.println();
			switch (number) {
			case 1:
				dnum = "college of arts and sciences";
				break;
			case 2:
				dnum = "college of built environments";
				break;
			case 3:
				dnum = "school of business";
				break;
			case 4:
				dnum = "school of computer science and engineering";
				break;
			case 5:
				dnum = "school of education";
				break;
			case 6:
				done = true;
				break;
			}

			try {

				System.out.println();
				String query = "SELECT * FROM student \r\n" + "INNER JOIN student_belong_department \r\n"
						+ "ON student.Ssn=student_belong_department.student_Ssn \r\n" + "INNER JOIN department \r\n"
						+ "ON student_belong_department.department_id=department.department_id\r\n"
						+ "INNER JOIN college \r\n" + "ON department.college_id=college.college_id\r\n"
						+ "where college_name LIKE ?";

				PreparedStatement prestmt = InternationalStudentMain.conn.prepareStatement(query);

				prestmt.setString(1, dnum);

				ResultSet rset = prestmt.executeQuery();

				System.out.println("   Student Information");
				System.out.println("--------------------------\n");
				System.out.println("   Ssn     Name");

				while (rset.next()) {
					int Ssn = rset.getInt("Ssn");
					String fname = rset.getString("first_name");
					String lname = rset.getString("last_name");

					System.out.println(Ssn + "    " + fname + " " + lname);
				}

			} catch (SQLException ex) {
				System.out.println(ex);
			}

		} while (!done);
	}

	// returns query of (school , degree , gpa) of input 'student' Ssn#.
	private static void educationalHistory() {
		try {
			System.out.print("Enter Student Ssn (#########): ");
			System.out.flush();
			String dnum = readLine();
			System.out.println();

			String query = "SELECT * FROM history where student_Ssn Like ?";

			PreparedStatement prestmt = InternationalStudentMain.conn.prepareStatement(query);

			prestmt.setString(1, dnum);

			ResultSet rset = prestmt.executeQuery();

			System.out.println("            Education History");
			System.out.println("--------------------------------------------------\n");

			while (rset.next()) {
				String school = rset.getString("school_name");
				String degree = rset.getString("degree");
				double gpa = rset.getDouble("gpa");

				System.out.println("College/School: " + school);
				System.out.println("        Degree: " + degree);
				System.out.println("           GPA: " + gpa);
				System.out.println();
			}

		} catch (SQLException ex) {
			System.out.println(ex);
		}

	}

	// Main menu
	private static void printMenu() {
		System.out.println();
		System.out.println("**************************************************");
		System.out.println("                  ***************");
		System.out.println("                  Welcome to the");
		System.out.println("     International Student Information System");
		System.out.println("                  ***************");
		System.out.println("                1.  Current Students");
		System.out.println("**************************************************");
		System.out.println("               1. Academic Information ");
		System.out.println("                2. Contact Information ");
		System.out.println("                  3. Visa Status");
		System.out.println("                     4. Quit");

	}

	// sub-Menu 1
	private static void printMenu1() {
		System.out.println();
		System.out.println("**************************************************");
		System.out.println("                  ***************");
		System.out.println("                  Welcome to the");
		System.out.println("     International Student Information System");
		System.out.println("                  ***************");
		System.out.println("                1. Academic Information");
		System.out.println("**************************************************");
		System.out.println("               1. Educational history ");
		System.out.println("               2. Student Information ");
		System.out.println("               3. Return to Previous Menu");

	}

	// sub-menu 2
	private static void printMenu2() {
		System.out.println();
		System.out.println("**************************************************");
		System.out.println("                  ***************");
		System.out.println("                  Welcome to the");
		System.out.println("     International Student Information System");
		System.out.println("                  ***************");
		System.out.println("                2. Contact Information");
		System.out.println("**************************************************");
		System.out.println("             1. Student Contact Information ");
		System.out.println("             2. Student Country of Origin ");
		System.out.println("             3. Working Student Contact Information");
		System.out.println("             4. Return to Previous Menu");

	}

	// sub-menu 3
	private static void printMenu3() {
		System.out.println();
		System.out.println("**************************************************");
		System.out.println("                  ***************");
		System.out.println("                  Welcome to the");
		System.out.println("     International Student Information System");
		System.out.println("                  ***************");
		System.out.println("                3. Visa Status");
		System.out.println("**************************************************");
		System.out.println("               1. Visa Status Report ");
		System.out.println("               2. F-1 visa ");
		System.out.println("               3. Return to Previous Menu ");

	}

// sub-menu 2 option 1 input choices
	private static void printMenu4() {
		System.out.println();
		System.out.println("**************************************************");
		System.out.println("1. college of arts and sciences");
		System.out.println("2. college of built environments");
		System.out.println("3. school of business");
		System.out.println("4. school of computer science and engineering");
		System.out.println("5. school of education");
		System.out.println("6.  Return to Previous Menu");
		System.out.println("**************************************************");

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
					currentStudentMenu();
				} catch (SQLException se) {
					System.out.println(se);
				}
				break;
			default:
				System.out.println(" Not a valid option ");
			}

		} while (!done);
	}

// reads input line from user
	private static String readLine() {
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr, 1);
		String line = "";

		try {
			line = br.readLine();
		} catch (IOException e) {
			System.out.println("Error in SimpleIO.readLine: " + "IOException was thrown");
			System.exit(1);
		}
		return line;
	}
}
