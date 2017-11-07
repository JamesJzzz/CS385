
// Zhiyuan(James) Zhang
// I pledge my honor that I have abided by the Stevens Honor System.
// ------James



package databaselab;
import java.sql.*;

public class databasehw1 {
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
	      String drop = "DROP DATABASE IF EXISTS BoatRental";
	      stmt.executeUpdate(drop);
	      String sql = "CREATE DATABASE IF NOT EXISTS BoatRental";
	      stmt.executeUpdate(sql);
	      System.out.println("Database created successfully...");
	      
	      //STEP 4: Use SQL to select the database;
	      sql = "use BoatRental";
	      stmt.executeUpdate(sql);
	  
	     //STEP 5: Use SQL to create Tables;
	     //STEP 5.1: Create Table Sailor;
	      sql = "create table Sailor(sid integer not null PRIMARY KEY, " +
	      		"sname varchar(20) not null," +
	      		"rating real," +
	      		"age integer)";
	      stmt.executeUpdate(sql);
	      
	      //STEP 5.2: Create Table Boats;
	      sql = "create table Boats (bid integer not null PRIMARY KEY, "+
	    		"bname varchar(40) not null, " +
	    		"color varchar(40))";
	      stmt.executeUpdate(sql);
	      
	     //STEP 5.3: Create Table Reserves;
	     //Your Task 1!
	      sql = "create table Reserves(sid integer not null," +
	    		"bid integer not null,"+
	    		"day date not null," +
	    		"PRIMARY KEY(sid, bid, day))";
	      stmt.executeUpdate(sql);
	      
	       //STEP 6: Use SQL to insert tuples into tables;
	       	sql = "insert into Sailor values(22, 'Dustin', 7, 45)";
	       	stmt.executeUpdate(sql);
	       	
	       	sql = "insert into Sailor values(29, 'Brutus', 1, 33)";
	       	stmt.executeUpdate(sql);
	       	
	       	sql = "insert into Sailor values(31, 'Lubber', 8, 55)";
	       	stmt.executeUpdate(sql);
	       	
	       	sql = "insert into Sailor values(32, 'Andy', 8, 26)";
	       	stmt.executeUpdate(sql);
	       	
	       	sql = "insert into Sailor values(58, 'Rusty', 10, 35)";
	       	stmt.executeUpdate(sql);
	       	
	       	sql = "insert into Sailor values(64, 'Horatio', 7, 35)";
	       	stmt.executeUpdate(sql);
	       	
	       	sql = "insert into Sailor values(71, 'Zorba', 20, 18)";
	       	stmt.executeUpdate(sql);
	       	
	       	sql = "insert into Sailor values(74, 'Horatio', 9, 35)";
	       	stmt.executeUpdate(sql);
	       	
	       	
	      //STEP 6.2: insert tuples into Table;
	       	sql = "insert into Boats values(101, 'Interlake', 'Blue')";
	       	stmt.executeUpdate(sql);
	       	
	       	sql = "insert into Boats values(102, 'Interlake', 'Red')";
	       	stmt.executeUpdate(sql);
	       	
	       	sql = "insert into Boats values(103, 'Clipper', 'Green')";
	       	stmt.executeUpdate(sql);
	       	
	       	sql = "insert into Boats values(104, 'Marine', 'Red')";
	       	stmt.executeUpdate(sql);
	       	
	       	
	       	// insert values into table Reserves;
	        sql = "insert into Reserves values(22,101, '08-10-10')";
	        stmt.executeUpdate(sql);
	        
	        sql = "insert into Reserves values(22,102, '08-10-10')";
	        stmt.executeUpdate(sql);
	        
	        sql = "insert into Reserves values(22,103, '09-10-08')";
	        stmt.executeUpdate(sql);
	        
	        sql = "insert into Reserves values(22,104, '09-10-09')";
	        stmt.executeUpdate(sql);
	        
	        sql = "insert into Reserves values(31,102, '08-11-10')";
	        stmt.executeUpdate(sql);
	        
	        sql = "insert into Reserves values(31,103, '08-11-06')";
	        stmt.executeUpdate(sql);
	        
	        sql = "insert into Reserves values(31,104, '08-11-12')";
	        stmt.executeUpdate(sql);
	        
	        sql = "insert into Reserves values(64,101, '08-09-05')";
	        stmt.executeUpdate(sql);
	        
	        sql = "insert into Reserves values(64,102, '08-09-08')";
	        stmt.executeUpdate(sql);
	        
	        sql = "insert into Reserves values(74,103, '08-09-08')";
	        stmt.executeUpdate(sql);
	        
	        
	        
	     
	        //STEP 7: Use SQL to ask queries and retrieve data from the tables;
	        //An example to retrieve branch ID, name, address from Table Branch, and display these values; 
//	        Statement s = conn.createStatement ();
//	        s.executeQuery ("SELECT branch_id, branch_name, branch_addr FROM branch");
//	        ResultSet rs = s.getResultSet ();
//	        int count = 0;
//	        while (rs.next ())
//	        {
//	            int idVal = rs.getInt ("branch_id");
//	            String nameVal = rs.getString ("branch_name");
//	            String addrVal = rs.getString ("branch_addr");
//	            System.out.println (
//	                    "branch id = " + idVal
//	                    + ", name = " + nameVal
//	                    + ", address = " + addrVal);
//	            ++count;
//	        }
//	        rs.close ();
//	        s.close ();
//	        System.out.println (count + " rows were retrieved\n");

	        //Your Task 7: Write SQL for Q1, Q2 and Q3 in Lab instruction and display the answers.
	        
	        //Q1:
	        Statement a = conn.createStatement();
	        a.executeQuery("SELECT sid FROM Sailor NATURAL JOIN Reserves NATURAL JOIN Boats WHERE color = 'Red' AND sid NOT IN "
	        		+ "(SELECT sid FROM Sailor NATURAL JOIN Reserves NATURAL JOIN Boats WHERE color = 'Green')");
	        ResultSet res = a.getResultSet();
	        int counter = 0;
	        System.out.println(
        			"Q1:");
	        while (res.next()){
	        	String sailorsid = res.getString("sid");
	        	
	        	System.out.println(
	        			"Sailor's sid = " + sailorsid);
	        	++counter;
	        }
	        res.close();
	        a.close();
	        System.out.println(counter + " rows were retrieved\n");
	        
	        //Q2
	        Statement b = conn.createStatement();
	        b.executeQuery("SELECT sname FROM Sailor NATURAL JOIN Reserves NATURAL JOIN Boats WHERE sid IN "
	        		+ "(SELECT sid FROM Sailor NATURAL JOIN Reserves NATURAL JOIN Boats WHERE sid NOT IN (SELECT sid FROM Sailor NATURAL JOIN Reserves NATURAL JOIN Boats "
	        		+ "WHERE color ='Red'))"
	        		);
	        ResultSet res1 = b.getResultSet();
	        int counter1 = 0;
	        System.out.println(
        			"Q2:");
	        while(res1.next()){
	        	String sailorname = res1.getString("sname");
	        	
	        	System.out.println(
	        			"Sailor's name = " + sailorname);
	        	++counter1;
	        }
	        res1.close();
	        b.close();
	        System.out.println(counter1 + " rows were retrieved\n");
	        
	        //Q3
	        Statement c = conn.createStatement();
	        c.executeQuery("SELECT sid, sname FROM Sailor WHERE rating > ALL"
	        		+ "(SELECT rating FROM Sailor WHERE sname = 'Horatio')");
	        ResultSet res2 = c.getResultSet();
	        int counter2 = 0;
	        System.out.println(
        			"Q3:");
	        while(res2.next()){
	        	String sailorsname = res2.getString("sname");
	        	
	        	System.out.println(
	        			"Sailor's name = " + sailorsname);
	        	++counter2;
	        }
	        res2.close();
	        c.close();
	        System.out.println(counter2 + " rows were retrieved\n");
	        
	        //Q4
	        Statement d = conn.createStatement();
	        d.executeQuery("SELECT S.sname FROM Sailor S WHERE NOT EXISTS"
	        		+ "(SELECT B.bid FROM Boats B WHERE NOT EXISTS"
	        		+ "(SELECT R.bid FROM Reserves R WHERE R.bid = B.bid AND R.sid = S.sid))");
	        ResultSet res3 = d.getResultSet();
	        int counter3 = 0;
	        System.out.println(
        			"Q4:");
	        while(res3.next()){
	        	String sailorssname = res3.getString("sname");
	        	
	        	System.out.println(
	        			"Sailor's name = " + sailorssname);
	        	++counter3;
	        }
	        res3.close();
	        d.close();
	        System.out.println(counter3 + " rows were retrieved\n");
	        
	        //Q5
	        Statement e = conn.createStatement();
	        e.executeQuery("SELECT bid, COUNT(*) AS sailorcount FROM Boats NATURAL JOIN Reserves WHERE color = 'Red' GROUP BY bid ");
	        ResultSet res4 = e.getResultSet();
	        int counter4 = 0;
	        System.out.println(
        			"Q5:");
	        while(res4.next()){
	        	String number = res4.getString("sailorcount");
	        	String boatid = res4.getString("bid");
	        	System.out.println(
	        			"The bid of the boat =" + boatid);
	        	System.out.println(
	        			"The number of reservations for this boat = " + number +"\n");
	        	
	        	++counter4;
	        }
	        res4.close();
	        e.close();
	        System.out.println(counter4 + " rows were retrieved\n");
	        
	        
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

