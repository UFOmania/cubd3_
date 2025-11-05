for i in $(seq 0 100); do
    echo "🧪 Testing TIME_ALLOCATED=$i"
	#sleep 1
    make fclean bonus  TIME_ALLOCATED=$i
    ./cub3D_bonus bonus/maps/map.cub
    sleep 4
    make clean
    echo "------------------------------------"
done
