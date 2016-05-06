create database arufmt;
use arufmt;
drop database aruftm;

create table temphum(	
	id integer unique auto_increment,
    temp varchar(10),
    hum	varchar(10),
    data_hora datetime
);

select * from temphum;	
truncate table temphum;
