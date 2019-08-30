# FT_LS - C - 2019  
FT_LS is a recreation of the unix function, ls.  

## WeThinkCode:

**Mandatory:** 100/100  
**Bonus:** 14/25  
**Peers:** 113% (avg)  
  
**Total:** 113/125

## Installation:

To get started, clone the FT_LS repo and go into the folder:

```
git clone https://github.com/FWMoor/ft_ls
cd ft_ls/
```
### Make:    

```
make
```

### Usage:

```
./ft_ls [-AGRaflnprt1] [file ...]  
```  

### Flags:  
```-A``` - Shows all files (including hidden files), but doesn't show the "." and ".." directories. (Bonus)  
```-G``` - Shows normal files, but adds colour. (Bonus)  
```-R``` - Shows all files recursively.  
```-a``` - Shows all files including "." and "..".  
```-f``` - Shows normal files, unsorted. (Bonus)  
```-l``` - Shows files in long format.  
```-n``` - Shows UID and GID in long format as a number. (Bonus)  
```-p``` - Adds a '/' to the back of directory names. (Bonus)  
```-r``` - Reverses the output.  
```-t``` - Sorts files according to time.  

## Helpers
[Frederick](https://github.com/fwmoor) - Mallocing and freeing.  
[Zia](https://github.com/ziadhorat) - Bonuses and long formatting.  
[Nolin](https://github.com/nreddystudent) - Sorting and error checks.  
