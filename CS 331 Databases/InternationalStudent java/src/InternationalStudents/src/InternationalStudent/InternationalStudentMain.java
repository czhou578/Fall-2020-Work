/*
CS 331 Database Design Fall 2020
Java Application for Group 1 - Project 1 "Project 1 International Student Information System"
By:  Colin Zhou, Ruiting Zhang, Samuel Faulkner

----------------------------------------------------------------------------------------------------------------------------

Description: Main Class initializes Connection to Database, initializes Main Class, and Closes Database connection.

*/

package InternationalStudent;

import java.util.*;
import java.io.*;
import java.sql.*;


public class InternationalStudentMain {
	public static Connection conn = null;
	
	public static void main(String args[]) throws SQLException{
		try {			
			DBConnection.connectToDB();
			MainInterface.mainInterface();
			DBConnection.closeDB();
		
		}catch(SQLException ex) {
   			System.out.println(ex);
   		}
	}
}
