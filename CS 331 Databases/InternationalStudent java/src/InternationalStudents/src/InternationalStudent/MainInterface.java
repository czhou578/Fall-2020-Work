/*
CS 331 Database Design Fall 2020
Java Application for Group 1 - Project 1 "Project 1 International Student Information System"
By:  Colin Zhou, Ruiting Zhang, Samuel Faulkner

----------------------------------------------------------------------------------------------------------------------

Description: Main menu UI: Calls classes : #1 currentStudentInterface() , #2 graduateStudentInterface() , 
                                           #3 internationalRuleInterface() , #4 updateInterface()
                                           
*/

package InternationalStudent;

import java.io.IOException;
import java.sql.SQLException;
import java.util.Scanner;

public class MainInterface {
	public static void mainInterface() throws SQLException {
		try {
			boolean done = false;
			do {
				printMenu();
				System.out.print("Type in your option: ");
				System.out.flush();
				Scanner input = new Scanner(System.in);
				int number = input.nextInt();
				System.out.println();

				switch (number) {
				case 1:
					CurrentStudent.currentStudentInterface();
					break;
				case 2:
					GraduatedStudent.graduateStudentInterface();
					break;
				case 3:
					InternationalRule.internationalRuleInterface();
					break;
				case 4:
					Updates.updateInterface();
					break;
				case 5:
					done = confirmation();
					break;
				default:
					System.out.println(" Not a valid option ");
				}
					
			} while (!done);
			
		} catch (SQLException ex) {
			System.out.println(ex);
			
		}

		
}

	private static void printMenu() {
		System.out.println();
		System.out.println("**************************************************");
		System.out.println("                  ***************");
		System.out.println("                  Welcome to the");
		System.out.println("     International Student Information System");
		System.out.println("                  ***************");
		System.out.println("**************************************************");
		System.out.println("                  1. Current Students ");
		System.out.println("                  2. Graduated Students ");
		System.out.println("                  3. International Rules & Laws");
		System.out.println("                  4. Updates");
		System.out.println("                  5. Quit");
	}

	// Escape from exiting
	private static boolean confirmation() {
		boolean done = false;
		
			System.out.println();
			System.out.print("Enter 1 to continue or 2 to cancel: ");
			System.out.println();
			Scanner input = new Scanner(System.in);
			int number = input.nextInt();

			switch (number) {
			case 1:
				done = true;
				break;
			case 2:
				done = false;
				break;
			default:
				System.out.println(" Not a valid option ");
			}

			return done;
	}
}
