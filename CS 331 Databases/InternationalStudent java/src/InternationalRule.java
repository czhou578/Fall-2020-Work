/*
CS 331 Database Design Fall 2020
Java Application for Group 1 - Project 1 "Project 1 International Student Information System"
By:  Colin Zhou, Ruiting Zhang, Samuel Faulkner

-----------------------------------------------------------------------------------------------------------------------------

Description: Main menu selection #3 database MySql query.
Finds: International Rules and Laws(ID , Name , Descriptions) 

*/
package InternationalStudent;

import java.io.IOException;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.io.*;
import java.util.*;

public class InternationalRule {
	public static void internationalRuleInterface()throws SQLException{
		try {
			if (askCredentials() == false) {
				return;
			} else {
				findRule();
				returnToMain();
				
			}
			
		} catch(SQLException se) {
			System.out.println(se);
		}

	}
	
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
		
	private static void findRule() throws SQLException{
		try {
	        Statement stmt = InternationalStudentMain.conn.createStatement();           
            String query = "select * from rules";          
            ResultSet rset = stmt.executeQuery(query);
         
            System.out.println("    International Rules and Laws");
            System.out.println("--------------------------------------------------\n");
            System.out.println("ID     Name          Description");
            
            while(rset.next()) {
            	int id = rset.getInt("rules_id");
            	String name = rset.getString("rules_name");
            	String description = rset.getString("rules_description");            	
            	System.out.println( id + "    " + name + "    " + description);
            }
	            
		}catch(SQLException ex) {
   			System.out.println(ex);
   		}
	}
	
	private static void returnToMain(){		
		boolean done = false;			
		do {
			System.out.println();
			System.out.print("Enter 1 to return to main interface: ");
			Scanner input = new Scanner(System.in);
			int number = input.nextInt();
			
			switch(number) {
				case 1:
					done = true;
					break;
				case 2:
					try {
						findRule();
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
