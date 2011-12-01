#include "tanggal.h"

tanggal BuatTanggal (int hari, int bulan, int tahun)
{
	tanggal t;
	t.hari=hari;
	t.bulan=bulan;
	t.tahun=tahun;
	return t;
}

int bandingtanggal (tanggal t1, tanggal t2)
{
	if (t1.tahun==t2.tahun)
	{
		if (t1.bulan==t2.bulan)
		{
			if (t1.hari==t2.hari)
			{
				return 0;
			}
			else if (t1.hari<t2.hari)
			{
				return -1;
			}
			else
			{
				return 1;
			}
		}
		else if (t1.bulan<t2.bulan)
		{
			return -1;
		}
		else
		{
			return 1;
		}
	}
	else if (t1.tahun<t2.tahun)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

bool IsKabisat (int tahun)
{
	if (tahun%400==0)
	{
		return true;
	}
	else if (tahun%100==0)
	{
		return false;
	}
	else if (tahun%4==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int selisihtanggal (tanggal t1, tanggal t2, int param)
{
	int bulan[12];
	int i=0,temp,total=0;
	
	for (i=0;i<8;i+=2)
	{
		bulan[i]=31;
		bulan[i+1]=30;
	}
	for (i=8;i<12;i+=2)
	{
		bulan[i]=30;
		bulan[i+1]=31;
	}
	bulan[1]=28;
	t1.bulan--;
	t2.bulan--;
	if (param==0)
	{
		if (t1.bulan<t2.bulan)
		{
			if (IsKabisat(t1.tahun))
			{
				bulan[1]=29;
			}
			for (i=t1.bulan+1;i<t2.bulan;++i)
			{
				total+=bulan[i];
			}
			total+=(bulan[t1.bulan]-t1.hari);
			total+=t2.hari;
			return total;
		}
		else if (t1.bulan>t2.bulan)
		{
			if (t1.bulan<=1)
			{
				if (IsKabisat(t1.tahun))
				{
					bulan[1]=29;
				}
			}
			else
			{
				if (IsKabisat(t1.tahun+1))
				{
					bulan[1]=29;
				}
			}
			for (i=t1.bulan+1;i<12;++i)
			{
				total+=bulan[i];
			}
			for (i=0;i<t2.bulan;++i)
			{
				total+=bulan[i];
			}
			total+=(bulan[t1.bulan]-t1.hari);
			total+=t2.hari;
			return total;
		}
		else
		{
			if (t1.hari<t2.hari)
			{
				total+=(t2.hari-t1.hari);
				return total;
			}
			else if (t1.hari>t2.hari)
			{
				if (t1.bulan==1)
				{
					if (IsKabisat(t1.tahun))
					{
						bulan[1]=29;
					}
				}
				else
				{
					if (IsKabisat(t1.tahun+1))
					{
						bulan[1]=29;
					}
				}
				for (i=t1.bulan+1;i<12;++i)
				{
					total+=bulan[i];
				}
				for (i=0;i<t1.bulan;++i)
				{
					total+=bulan[i];
				}
				total+=(bulan[t1.bulan]-t1.hari);
				total+=t2.hari;
				return total;
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		if (t1.bulan<t2.bulan)
		{
			if (t1.bulan<=1)
			{
				if (IsKabisat(t1.tahun))
				{
					bulan[1]=29;
				}
			}
			else
			{
				if (IsKabisat(t1.tahun-1))
				{
					bulan[1]=29;
				}
			}
			for (i=0;i<t1.bulan;++i)
			{
				total+=bulan[i];
			}
			for (i=t2.bulan+1;i<12;++i)
			{
				total+=bulan[i];
			}
			total+=(bulan[t2.bulan]-t2.hari);
			total+=t1.hari;
			total*=-1;
			return total;
		}
		else if (t1.bulan>t2.bulan)
		{
			if (IsKabisat(t1.tahun))
			{
				bulan[1]=29;
			}
			for (i=t2.bulan+1;i<t1.bulan;++i)
			{
				total+=bulan[i];
			}
			total+=(bulan[t2.bulan]-t2.hari);
			total+=t1.hari;
			total*=-1;
			return total;
		}
		else
		{
			if (t1.hari>t2.hari)
			{
				total+=(t1.hari-t2.hari);
				total*=-1;
				return total;
			}
			else if (t2.hari>t1.hari)
			{
				if (t1.bulan==1)
				{
					if (IsKabisat(t1.tahun))
					{
						bulan[1]=29;
					}
				}
				else
				{
					if (IsKabisat(t1.tahun-1))
					{
						bulan[1]=29;
					}
				}
				for (i=0;i<t1.bulan;++i)
				{
					total+=bulan[i];
				}
				for (i=t1.bulan+1;i<12;++i)
				{
					total+=bulan[i];
				}
				total+=(bulan[t2.bulan]-t2.hari);
				total+=t1.hari;
				total*=-1;
				return total;
			}
			else
			{
				return 0;
			}
		}
	}
}
