/*
CS 331 Database Design Fall 2020
Java Application for Group 1 - Project 1 "Project 1 International Student Information System"
By:  Colin Zhou, Ruiting Zhang, Samuel Faulkner

-----------------------------------------------------------------------------------------------------------------------------
Description: Main menu selection #2 database MySql query. 
Finds: Will be the future implementation class for Database SQL queries for Graduated Students. 

*/

package InternationalStudent;

import java.sql.Connection;
import java.sql.SQLException;
import java.util.Scanner;


public class GraduatedStudent {

		Connection conn = null;
	
//
	public static void graduateStudentInterface()throws SQLException{
		try {
				if (askCredentials() == false) { // Authenticates User
					return;
				} else {
					currentGradStudentMenu();	
					returnToMain();
				}
				
			} catch(SQLException se) {
				System.out.println(se);
			}

		}
		
	//User verification
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
		 
		// UI for class menu 1
		 static void currentGradStudentMenu() throws SQLException { 
		        boolean done = false;
				do {
					printMenu();
					System.out.println();
					System.out.print("Type in your option: ");
				    Scanner input = new Scanner(System.in);
				    int number = input.nextInt();
				    System.out.println();
					switch(number) {
						case 1:
							done = true;
							break;			
					}			
					
				} while (!done);
			}
		 
		 
		//Menu 1 for UI
			private static void printMenu() { 
		        System.out.println();
		        System.out.println("**************************************************");
		        System.out.println("                  ***************");
		        System.out.println("                  Welcome to the");
		        System.out.println("     International Student Information System");
		        System.out.println("                  ***************");
		        System.out.println("                2.  Graduate Students");
		        System.out.println("**************************************************");
		        System.out.println("                     1. quit ");
		        
			}       
		    
		
			// Return to Main Menu escape
		 private static void returnToMain(){		
				boolean done = false;			
				do {
					System.out.println();
					System.out.println("Enter 1 to return to main interface or 2 to cancel: ");
					System.out.println();
					Scanner input = new Scanner(System.in);
					int number = input.nextInt();
					
					switch(number) {
						case 1:
							done = true;
							break;
						case 2:
						try {
							currentGradStudentMenu();
						} catch (SQLException se) {
							System.out.println(se);
						}
							break;
						default:
							System.out.println(" Not a valid option ");
					}	
					
				}while(!done);								
			}

}