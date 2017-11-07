public class largestprimefactor{

	public static void main(String[] args){
		long start = System.nanoTime();
		int i= 2;
		long n = 600851475143L;
		int max_factor = (int) Math.sqrt(n);
		while(i< max_factor){
			if(n% i == 0){
				n /= i;
				System.out.println(i);
				max_factor = (int) Math.sqrt(n);
			}
			else{
				i++;
			}
		}
		System.out.println(n);
		double elapsed = (System.nanoTime() - start) / 1e6;
		System.out.println("Elapsed time : " + elapsed + " ms");

	}
}