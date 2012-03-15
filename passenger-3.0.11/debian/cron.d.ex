#
# Regular cron jobs for the passenger package
#
0 4	* * *	root	[ -x /usr/bin/passenger_maintenance ] && /usr/bin/passenger_maintenance
