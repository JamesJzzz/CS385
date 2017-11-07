

// Zhiyuan(James) Zhang
// I pledge my honor that I have abided by the Stevens Honor System.
// ------James

package databaselab;
import java.sql.*;

public class example {
   // JDBC driver name and database URL
   static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";  
   static final String DB_URL = "jdbc:mysql://localhost/test";

   //  Database credentials
   static final String USER = "root";
   //the user name; You can change it to your username (by default it is root).
   static final String PASS = ""; 
   //the password; You can change it to your password (the one you used in MySQL server configuration).
   
   public static void main(String[] args) {
   Connection conn = null;
   Statement stmt = null;
   try{
      //STEP 1: Register JDBC driver
      Class.forName("com.mysql.jdbc.Driver");

      //STEP 2: Open a connection to database
      System.out.println("Connecting to database...");
      conn = DriverManager.getConnection(DB_URL, USER, PASS);

      System.out.println("Creating database...");
      stmt = conn.createStatement();

      //STEP 3: Use SQL to Create Database; 
      String drop = "DROP DATABASE IF EXISTS VehicleOffice";
      stmt.executeUpdate(drop);
      String sql = "CREATE DATABASE IF NOT EXISTS VehicleOffice";
      stmt.executeUpdate(sql);
      System.out.println("Database created successfully...");
      
      //STEP 4: Use SQL to select the database;
      sql = "use VehicleOffice";
      stmt.executeUpdate(sql);
  
     //STEP 5: Use SQL to create Tables;
     //STEP 5.1: Create Table Branch;
      sql = "create table Branch( branch_id integer not null PRIMARY KEY, " +
      		"branch_name varchar(20) not null," +
      		"branch_addr varchar(50)," +
      		"branch_city varchar(20) not null," +
      		"branch_phone integer)";
      stmt.executeUpdate(sql);
      
      //STEP 5.2: Create Table Driver;
      sql = "create table Driver(driver_ssn integer not null PRIMARY KEY," +
      		"driver_name varchar(20) not null," +
      		"driver_addr varchar(50) not null," +
      		"driver_city varchar(20) not null," +
      		"driver_birthdate date not null," +
      		"driver_phone integer)";
      stmt.executeUpdate(sql);
      
     //STEP 5.3: Create Table License;
     //Your Task 1!
      sql = "create table License( license_no integer not null PRIMARY KEY," + 
    		"driver_ssn integer," + 
    		"license_type char not null," + 
    		"license_class integer," + 
    		"license_experation date not null," + 
    		"issue_date date not null," + 
    		"branch_id integer)";
      stmt.executeUpdate(sql);
      
      //STEP 5.4: Create Table Exam;
      //Your Task 2!
      sql = "create table Exam( driver_ssn integer not null," + 
    		"branch_id integer not null," + 
    		"exam_date date not null," + 
    		"exam_type char," + 
    		"exam_score integer," +
    		"PRIMARY KEY(driver_ssn,branch_id,exam_date))";
      stmt.executeUpdate(sql);

      
       //STEP 6: Use SQL to insert tuples into tables;
       //STEP 6.1: insert tuples into Table Branch;
        sql = "insert into branch values(10, 'Main', '1234 Main St.', 'Vancouver', 5551234)";
        stmt.executeUpdate(sql);
        
        sql = "insert into branch values(20, 'Richmond', '23 No.3 Road', 'Richmond', 5552331)";
        stmt.executeUpdate(sql);

        //Your Task 3: insert the rest of tuples in Table Branch;
        sql = "insert into branch values(30, 'West Creek', '251 Creek Rd.', 'Sechelt', 5552511)";
        stmt.executeUpdate(sql);
        
        sql = "insert into branch values(40, 'Blenheim', '1342 W.22 Ave.', 'Burnaby', 5551342)";
        stmt.executeUpdate(sql);
        
       //STEP 6.2: insert tuples into Table driver;
        sql = "insert into driver values(111111111, 'Bob Smith', '111 E. 11 St.', 'Vancouver', '1975-01-01', 5551111)";
        stmt.executeUpdate(sql);
        
        sql = "insert into driver values(222222222, 'John Walters', '222 E. 22 St.', 'Burnaby', '1976-02-02', 5552222)";
        stmt.executeUpdate(sql);

      //Your Task 4: insert the rest of tuples in Table Driver;
        sql = "insert into driver values(333333333, 'Troy Rops', '333 W. 33 Ave.', 'Richmond', '1970-03-03', 5553333)";
        stmt.executeUpdate(sql);
        
        sql = "insert into driver values(444444444, 'Kevin Mark', '444 E. 3 Ave.', 'Vancouver', '1974-04-04', 5554444)";
        stmt.executeUpdate(sql);
        
      //STEP 6.3: insert tuples into Table license;
      //Your Task 5: insert all tuples into Table license;
        sql = "insert into license values(1, 111111111, 'D', 5, '1999-05-25', '1997-05-25', 20)";
        stmt.executeUpdate(sql);
        
        sql = "insert into license values(2, 222222222, 'D', 5, '1998-08-29', '1996-08-29', 40)";
        stmt.executeUpdate(sql);
        
        sql = "insert into license values(3, 333333333, 'L', 5, '1997-12-27', '1997-06-27', 20)";
        stmt.executeUpdate(sql);
        
        sql = "insert into license values(4, 444444444, 'D', 5, '1999-08-30', '1997-08-30', 40)";
        stmt.executeUpdate(sql);
        
        
      //STEP 6.4: insert all tuples into Table exam;
      //Your Task 6: insert all tuples into Table exam;
        
        sql = "insert into exam values(111111111, 20, '1997-05-25', 'D', 79)";
        stmt.executeUpdate(sql);
        
        sql = "insert into exam values(111111111, 20, '1997-12-02', 'L', 97)";
        stmt.executeUpdate(sql);
        
        sql = "insert into exam values(222222222, 30, '1996-05-06', 'L', 25)";
        stmt.executeUpdate(sql);
        
        sql = "insert into exam values(222222222, 40, '1996-06-10', 'L', 51)";
        stmt.executeUpdate(sql);
        
        sql = "insert into exam values(222222222, 40, '1996-08-29', 'D', 81)";
        stmt.executeUpdate(sql);
        
        sql = "insert into exam values(333333333, 10, '1997-07-07', 'L', 45)";
        stmt.executeUpdate(sql);
        
        sql = "insert into exam values(333333333, 20, '1997-06-27', 'L', 49)";
        stmt.executeUpdate(sql);
        
        sql = "insert into exam values(333333333, 20, '1997-07-27', 'L', 61)";
        stmt.executeUpdate(sql);        
        
        sql = "insert into exam values(444444444, 10, '1997-07-27', 'L', 71)";
        stmt.executeUpdate(sql);
        
        sql = "insert into exam values(444444444, 20, '1997-08-30', 'D', 65)";
        stmt.executeUpdate(sql);
        
        
        //STEP 7: Use SQL to ask queries and retrieve data from the tables;
        //An example to retrieve branch ID, name, address from Table Branch, and display these values; 
        Statement s = conn.createStatement ();
        s.executeQuery ("SELECT branch_id, branch_name, branch_addr FROM branch");
        ResultSet rs = s.getResultSet ();
        int count = 0;
        while (rs.next ())
        {
            int idVal = rs.getInt ("branch_id");
            String nameVal = rs.getString ("branch_name");
            String addrVal = rs.getString ("branch_addr");
            System.out.println (
                    "branch id = " + idVal
                    + ", name = " + nameVal
                    + ", address = " + addrVal);
            ++count;
        }
        rs.close ();
        s.close ();
        System.out.println (count + " rows were retrieved\n");

        //Your Task 7: Write SQL for Q1, Q2 and Q3 in Lab instruction and display the answers.
        
        //Q1:
        /*
        Statement a = conn.createStatement();
        a.executeQuery("SELECT driver_name FROM driver, license, branch WHERE driver.driver_ssn = license.driver_ssn AND license.branch_id = branch.branch_id AND branch.branch_name = 'Richmond'");
        ResultSet res = a.getResultSet();
        int counter = 0;
        while (res.next()){
        	String drivername = res.getString("driver_name");
        	System.out.println(
        			"driver's name = " + drivername);
        	++counter;
        }
        res.close();
        a.close();
        System.out.println(counter + "rows were retrieved\n");
        */
        Statement q1 = conn.createStatement();
        q1.executeQuery("SELECT driver_name FROM driver, branch, license WHERE driver.driver_ssn = license.driver_ssn AND license.branch_id = branch.branch_id AND branch.branch_name = 'Richmond'");
        ResultSet rsq1 = q1.getResultSet();
        int counter = 0;
        while (rsq1.next()) {
            String nameVal = rsq1.getString("driver_name");
            System.out.println("QUESTION 1 "+"driver_name = " + nameVal);
            ++counter;
        }
        rsq1.close();
        q1.close();
        System.out.println(counter + " rows were retrieved");
        
        //Q2
        Statement b = conn.createStatement();
        b.executeQuery("SELECT driver_name FROM exam, driver WHERE exam.driver_ssn = driver.driver_ssn"
        		+ " GROUP BY exam.driver_ssn, branch_id, driver_name HAVING count(*) >= 2");
        ResultSet result = b.getResultSet();
        int count1 = 0;
        while (result.next()){
        	String drivername1 = result.getString("driver_name");
        	System.out.println(
        			"driver's name = " + drivername1);
        	++count1;
        }
        result.close();
        b.close();
        System.out.println(count1 + " rows were retrieved\n");
        
        
        //Q3
        Statement c = conn.createStatement();
        c.executeQuery("SELECT DISTINCT driver_name FROM driver WHERE driver.driver_ssn NOT IN (SELECT DISTINCT e.driver_ssn FROM exam e, exam e2 WHERE e.driver_ssn = e2.driver_ssn AND e.exam_date > e2.exam_date AND e.exam_score > e2.exam_score)");
        ResultSet answer = c.getResultSet();
        int count2 = 0;
        while (answer.next()){
        	String drivername2 = answer.getString("driver_name");
        	System.out.println(
        			"driver's name = " + drivername2);
        	++count2;
        }
        answer.close();
        c.close();
        System.out.println(count2 + "rows were retrieved\n");
        
        
        
        
      }catch(SQLException se){
      //Handle errors for JDBC
      se.printStackTrace();
   }catch(Exception e){
      //Handle errors for Class.forName
      e.printStackTrace();
   }finally{
      //finally block used to close resources
      try{
         if(stmt!=null)
            stmt.close();
      }catch(SQLException se2){
      }// nothing we can do
      try{
         if(conn!=null)
            conn.close();
      }catch(SQLException se){
         se.printStackTrace();
      }//end finally try
   }//end try
   System.out.println("Goodbye!");
}//end main
}//end JDBCExample











