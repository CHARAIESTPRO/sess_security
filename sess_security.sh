GREEN="\e[32m"

function starter()
{
read -s -t 3 pass
if [[ $? -gt 128 ]] ; then
    ft_lock && exit 42
else
	case $pass in
		60065)
			echo -n -e "${GREEN}Welcome back king"
			exit 13
		;;

		*)
			ft_lock 
		;;
	esac
fi
exit 42
}

function no_ctrlc()
{
	exit 42
}

trap no_ctrlc 2 3

while true
do
	starter
done
exit 42