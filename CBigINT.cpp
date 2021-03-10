#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_SIZE 10000
string CBigINT_add (string s1, string s2);
string CBigINT_mul (string s1, string s2);
string CBigINT_sub (string s1, string s2);
string CBigINT_max (string s1, string s2);
string CBigINT_min (string s1, string s2);
ll general_gcd (ll a, ll b);
ll CBigINT_gcd (ll a, string b);
ll CBigINT_mod (ll a, string b);
string CBigINT_abs (string s);
string CBigINT_factorial (ll num);
ll modify (ll x, ll vecsize, vector < int >&vec);
string CBigINT_factorial (ll num);
bool CBigINT_prime (ll n);
void CBigINT_increase (string & s);
void CBigINT_decrease (string & s);
void CBigINT_nextPerm (string & s);
void CBigINT_prevPerm (string & s);
//.............................................................................................//
				    //STARTING OF CODE//
//return integer corresponding to character
int
A (char ch)
{
  return int (ch) - 48;
}

//add two big integers
string
CBigINT_add (string s1, string s2)
{
  int l1 = s1.length (), l2 = s2.length ();
  int i = l1 - 1, j = l2 - 1;
  string res = "";
  int carry = 0;

  while (i >= 0 && j >= 0)
    {
      int val = A (s1[i]) + A (s2[j]) + carry;
      i--, j--;
      if (val >= 10)
	{
	  val -= 10;
	  carry = 1;
	}
      else
	{
	  carry = 0;
	}
      res += to_string (val);
    }
  if (l1 == l2)
    {
      if (carry == 1)
	{
	  res += "1";
	}
    }
  else if (l1 > l2)
    {
      while (i >= 0)
	{
	  int val = A (s1[i]) + carry;
	  if (val >= 10)
	    {
	      val -= 10;
	    }
	  else
	    {
	      carry = 0;
	    }
	  res += to_string (val);
	  i--;
	}
      if (carry == 1)
	{
	  res += "1";
	}
    }
  else if (l1 < l2)
    {
      while (j >= 0)
	{
	  int val = A (s2[j]) + carry;
	  if (val >= 10)
	    {
	      val -= 10;
	    }
	  else
	    {
	      carry = 0;
	    }
	  res += to_string (val);
	  j--;
	}
      if (carry == 1)
	{
	  res += "1";
	}
    }
  reverse (res.begin (), res.end ());
  return res;
}

//
ll
modify (ll x, ll vecsize, vector < int >&vec)
{
  ll carry = 0;
  for (ll i = 0; i < vecsize; i++)
    {
      ll product = vec[i] * x + carry;
      vec[i] = product % 10;
      carry = product / 10;
    }
  while (carry != 0)
    {
      vec[vecsize] = carry % 10;
      carry /= 10;
      vecsize++;
    }
  return vecsize;

}

//find factorial of a big integer
string
CBigINT_factorial (ll num)
{
  vector < int >vec (MAX_SIZE);
  vec[0] = 1;
  ll vecsize = 1;
  for (ll i = 2; i <= num; i++)
    {
      vecsize = modify (i, vecsize, vec);
    }
  string s = "";
  for (ll i = vecsize - 1; i >= 0; i--)
    {
      s += to_string (vec[i]);
    }
  return s;
}

//find maximum of the two big integers
string
CBigINT_max (string s1, string s2)
{
  int l1 = s1.length (), l2 = s2.length ();
  if (l1 > l2)
    {
      return s1;
    }
  if (l2 > l1)
    {
      return s2;
    }
  int i = 0, j = 0;
  while (s1[i] == s2[j])
    {
      i++, j++;
    }
  return (s1[i] > s2[j]) ? s1 : s2;
}

//find minimum of the two big integers
string
CBigINT_min (string s1, string s2)
{
  int l1 = s1.length (), l2 = s2.length ();
  if (l1 > l2)
    {
      return s2;
    }
  if (l2 > l1)
    {
      return s1;
    }
  int i = 0, j = 0;
  while (s1[i] == s2[j])
    {
      i++, j++;
    }
  return (s1[i] > s2[j]) ? s2 : s1;
}

//
ll
general_gcd (ll a, ll b)
{
  if (b == 0)
    {
      return a;
    }
  return general_gcd (b, a % b);
}

//
ll
CBigINT_mod (ll a, string b)
{
  ll mod = 0;
  for (int i = 0; i < b.size (); i++)
    {
      mod = (mod * 10 + b[i] - '0') % a;
    }
  return mod;
}

//find gcd of two big integers
ll
CBigINT_gcd (ll a, string b)
{
  ll reduced_b = CBigINT_mod (a, b);
  return general_gcd (a, reduced_b);

}

//returns absolute value of big integer
string
CBigINT_abs (string s)
{
  int l = s.length ();
  if (s[0] == '-')
    {
      s = s.substr (1);
    }
  return s;
}

//returns whether the big integer is prime or not
bool
CBigINT_prime (ll n)
{
  ll c = 0;
  for (ll i = 2; i <= sqrt (n); i++)
    {
      if (n % i == 0)
	{
	  if (n / i == i)
	    {
	      c += 1;
	    }
	  else
	    {
	      c += 2;
	    }

	}


    }

  return (c == 0) ? true : false;

}

//multiplies two big integers
string
CBigINT_mul (string num1, string num2)
{
  int len1 = num1.size ();
  int len2 = num2.size ();
  if (len1 == 0 || len2 == 0)
    return "0";


  vector < int >result (len1 + len2, 0);


  int i_n1 = 0;
  int i_n2 = 0;


  for (int i = len1 - 1; i >= 0; i--)
    {
      int carry = 0;
      int n1 = num1[i] - '0';


      i_n2 = 0;


      for (int j = len2 - 1; j >= 0; j--)
	{

	  int n2 = num2[j] - '0';


	  int sum = n1 * n2 + result[i_n1 + i_n2] + carry;

	  carry = sum / 10;


	  result[i_n1 + i_n2] = sum % 10;

	  i_n2++;
	}


      if (carry > 0)
	result[i_n1 + i_n2] += carry;


      i_n1++;
    }


  int i = result.size () - 1;
  while (i >= 0 && result[i] == 0)
    i--;


  if (i == -1)
    return "0";


  string s = "";

  while (i >= 0)
    s += std::to_string (result[i--]);

  return s;
}

//increment the big integer by 1
void
CBigINT_increase (string & s)
{
  string p = "1";
  string res = CBigINT_add (s, p);
  s = res;
}

//decrement the big integer by 1
void
CBigINT_decrease (string & s)
{
  string p = "1";
  string res = CBigINT_sub (s, p);
  s = res;
}

//subtract big integers
string
CBigINT_sub (string s1, string s2)
{
  string str1 = CBigINT_max (s1, s2);
  string str2 = CBigINT_min (s1, s2);


  string str = "";


  int n1 = str1.length (), n2 = str2.length ();
  int diff = n1 - n2;


  int carry = 0;


  for (int i = n2 - 1; i >= 0; i--)
    {

      int sub = ((str1[i + diff] - '0') - (str2[i] - '0') - carry);
      if (sub < 0)
	{
	  sub = sub + 10;
	  carry = 1;
	}
      else
	carry = 0;

      str.push_back (sub + '0');
    }


  for (int i = n1 - n2 - 1; i >= 0; i--)
    {
      if (str1[i] == '0' && carry)
	{
	  str.push_back ('9');
	  continue;
	}
      int sub = ((str1[i] - '0') - carry);
      if (i > 0 || sub > 0)
	str.push_back (sub + '0');
      carry = 0;
    }


  reverse (str.begin (), str.end ());

  return str;


}

//find next permutation of big integer
void
CBigINT_nextPerm (string & s)
{
  int l = s.length ();
  int index = -1;
  if (l == 0)
    {
      return;
    }
  if (l == 1)
    {
      return;
    }
  for (int i = l - 2; i >= 0; i--)
    {
      if (s[i] < s[i + 1])
	{
	  index = i;
	  break;
	}
    }
  if (index == -1)
    {
      return;
    }
  int num = s[index] - '0', maxnum = INT_MAX;
  int index2;
  for (int i = index; i < l; i++)
    {
      int val = s[i] - '0';
      if (val > num && val < maxnum)
	{
	  index2 = i;
	  maxnum = val;
	}

    }
  swap (s[index], s[index2]);
  sort (s.begin () + index + 1, s.end ());
}

//find the previous permutation of the big integer
void
CBigINT_prevPerm (string & s)
{
  int l = s.length ();
  if (l == 0 || l == 1)
    {
      return;
    }
  int index = -1;
  for (int i = l - 2; i >= 0; i++)
    {
      if (s[i] > s[i + 1])
	{
	  index = i;
	  break;
	}
    }
  int index2, minnum = INT_MIN;
  int num = s[index] - '0';
  for (int i = index + 1; i < l; i++)
    {
      int val = s[i] - '0';
      if (val < num && val > minnum)
	{
	  index2 = i;
	  minnum = val;
	}
    }
  swap (s[index], s[index2]);
  sort (s.begin () + index + 1, s.end (), greater < int >());
}

//...........................................................................................//
				 //END OF CODE//
