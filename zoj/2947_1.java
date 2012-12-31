import java.util.HashMap;
import java.util.Scanner;

/**
 * 
 */

/**
 * @author zhouyu
 *
 */
public class Main 
{
	/**
	 * @param args
	 */
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		while(sc.hasNextInt())
		{
			int n = sc.nextInt();
			for(int i = 0;i < n;i++)
			{
				int	an = sc.nextInt();
				sc.nextLine();
				String a = sc.nextLine();
				int	bn = sc.nextInt();
				sc.nextLine();
				String b = sc.nextLine();
				if(an != bn)
				{
					System.out.println("DIFFERENT");
					continue;
				}
				else
				{
					String[] awords = a.split(" ");
					String[] bwords = b.split(" ");
					String aAbbreviation = "";
					String bAbbreviation = "";
					for(int j = 0;j < an;j++)
					{
						aAbbreviation += awords[j].charAt(0);
						bAbbreviation += bwords[j].charAt(0);
					}
					if(aAbbreviation.equals(bAbbreviation))
						System.out.println("SAME");
					else
						System.out.println("DIFFERENT");
				}
				
			}
		}
	}
}
