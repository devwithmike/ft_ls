int main (int ac, char **av)
{
unsigned char flags;

	struct dirent *de;

    DIR *dr = opendir(".");
    flags = get_flags(ac, av);

    if (dr == NULL)
    {
        printf("Could not open current directory");
        return 0;
    }
    while ((de = readdir(dr)) != NULL)
    	if (!flags)
    	{
    		if (de->d_name[0] != '.')
        		printf("%s\t", de->d_name);
        }
    	else
    		if	((flags & 2) && (!(flags & 1) && (!(flags & 4)
    			&& (!(flags & 8)) && (!(flags & 16)))))
    			printf("%s\t", de->d_name);
	if (flags & 1)
    	printf("The flag l is there... but I ain't handeling that shit yet\n");
    if (flags & 4)
    	printf("The flag R is there... but I ain't handeling that shit yet\n");
    if (flags & 8)
    	printf("The flag r is there... but I ain't handeling that shit yet\n");
   	if (flags & 16)
    	printf("The flag t is there... but I ain't handeling that shit yet\n");
    printf("\n");
    closedir(dr);
	return (0);

}
