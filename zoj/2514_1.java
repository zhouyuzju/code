import java.util.Scanner;


public class Main 
{
	public static void GeneratePasswords()
	{
		Scanner sc = new Scanner(System.in);
		while(true)
		{
			int num = Integer.parseInt(sc.nextLine());
			if(num == 0)
				break;
			int count = 0;
			String out = "";
			for(int i = 0;i < num;i++)
			{
				String team = sc.next();
				String account = sc.nextLine();
				String newline = "";
				for(int j = 0;j < account.length();j++)
				{
					if(account.charAt(j) == '1')
						newline += '@';
					else if (account.charAt(j) == '0')
						newline += '%';
					else if (account.charAt(j) == 'l')
						newline += 'L';
					else if (account.charAt(j) == 'O')
						newline += 'o';
					else
						newline += account.charAt(j);
				}
				if(!account.equals(newline))
				{
					out += team + newline + "\n";
					count++;
				}
			}
			if(count == 0)
			{
				System.out.println("No account is modified.");
			}
			else
			{
				System.out.println(count);
				System.out.print(out);
			}
		}
	}
	public static void main(String[] args)
	{
		GeneratePasswords();
	}
}
