import java.sql.*;
import java.io.*;

public class test {

  public static void main(String args[]) {

    Connection conn = null;
    try {
      Class.forName("com.mysql.cj.jdbc.Driver");
      String url = "jdbc:mysql://localhost:3306/Company?serverTimezone=UTC&useSSL=TRUE";
      String user, pass;
      user = readEntry("User Id: ");
      pass = readEntry("User password: ");
      conn = DriverManager.getConnection(url, user, pass);
      if (conn != null) {
          System.out.println("Connected to Database");
          DatabaseMetaData dm = conn.getMetaData();
          System.out.println("Driver name: " + dm.getDriverName());
       }


    } catch (ClassNotFoundException | SQLException e) {
      System.out.println(e.getMessage());
    }
        
  }

  private static String readEntry(String string) {
	  try {
		 StringBuffer buffer = new StringBuffer();
	    System.out.print(string);
	    System.out.flush();
	    int c = System.in.read();
	    while(c != '\n' && c != -1) {
	      buffer.append((char)c);
	      c = System.in.read();
	    }
	    return buffer.toString().trim();
		
	} catch (IOException e) {
		return "";
	}
	}
}