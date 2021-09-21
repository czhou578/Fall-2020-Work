/*
CS 331 Database Design Fall 2020
Java Application for Group 1 - Project 1 "Project 1 International Student Information System"
By:  Colin Zhou, Ruiting Zhang, Samuel Faulkner

---------------------------------------------------------------------------------------------------------------------------------------

Description: Connects to database by providing mysql Driver to use , and IP/port information of the database server to be connected.

*/

package InternationalStudent;

import java.util.*;
import java.io.*;
import java.sql.*;

public class DBConnection {
	public static void connectToDB() {				
		try {           
            Class.forName("com.mysql.cj.jdbc.Driver"); // Loading Class
            String url = "jdbc:mysql://127.0.0.1:3306/InternationalStudent"; // path to database server
            String user = "student";
            String pass = "password";                    
            InternationalStudentMain.conn = DriverManager.getConnection(url, user, pass); // Database login credentials 
            
		}catch (ClassNotFoundException e) {
			System.out.println("Could not load the driver");
			
		} catch (SQLException ex) {
			System.out.println(ex);
		}
	}
	
	public static void closeDB() {
		if (InternationalStudentMain.conn != null) {
            try {
            	InternationalStudentMain.conn.close();
            } catch (SQLException e) {   
                System.out.println(e);
            }
        }
	}
}
