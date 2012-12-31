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
	private static int MAXDIGIT = 25;
	/**
	 * @param args
	 */
	public static void main(String[] args) 
	{
		int[] prim = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		String line = "";
		while(sc.hasNext())
		{
			line = sc.nextLine();
			String[] strdigit = line.split(" ");
			String[] strleftdigits = strdigit[0].split(",");
			String[] strrightdigits = strdigit[1].split(",");
			int[] leftdigits = new int[MAXDIGIT];
			int[] rightdigits = new int[MAXDIGIT];
			for(int i = strleftdigits.length - 1, j = 0;i >= 0 ;i--)
			{
				leftdigits[j++] = Integer.parseInt(strleftdigits[i]);
			}
			for(int i = strrightdigits.length - 1, j = 0;i >= 0 ;i--)
			{
				rightdigits[j++] = Integer.parseInt(strrightdigits[i]);
			}
			if(strleftdigits.length == 1 && strrightdigits.length == 1 && leftdigits[0] == 0 && rightdigits[0] == 0)
			{
				System.out.println(0);
				continue;
			}
			int[] result = new int[MAXDIGIT + 1];
			for(int i = 0;i < MAXDIGIT;i++)
			{
				int add = result[i] + leftdigits[i] + rightdigits[i];
				if(add / prim[i] == 1)
				{
					result[i + 1] = 1;
					result[i] = add % prim[i];
				}
				else
				{
					result[i] = add;
				}
			}
			boolean flag = false;
			for(int i = MAXDIGIT;i >= 0 ;i--)
			{
				if(result[i] != 0 && !flag)
				{ 
					flag = true;
					System.out.print(result[i]);
				}
				else if(flag)
				{
					System.out.print("," + result[i]);
				}
			}
			System.out.println();
		}
	}
}
