#include "pch.h"
#include "../BetterGameTracker/src/ResultObject.h"
#include <sstream>
#include <fstream>
TEST(results, can_use_them) 
{
	auto r = ResultObject();
	std::stringstream s = std::stringstream();
	std::ostream* o = &s;
	std::istream* i = &s;
	r.lose();
	r.win();
	r.win();
	r.mode = "Rumble";
	r.save(o);	
	//EXPECT_TRUE(false) << o;
	auto objs = ResultObject::load(i);
	auto new_r = objs["Rumble"];
	EXPECT_TRUE(new_r->losses == 1);
	EXPECT_TRUE(new_r->wins == 2);
	EXPECT_TRUE(new_r->streak == 1);
	EXPECT_TRUE(new_r->mode == "Rumble");
	EXPECT_TRUE(new_r->previous == BGT::Types::Result::Result_WIN);
}

TEST(results, can_save_them_and_load_them_from_file)
{
	std::ofstream o = std::ofstream("foobar.dat", std::ios_base::binary);
	std::ostream* os = &o;
	auto r = ResultObject();
	r.lose();
	r.win();
	r.win();
	r.mode = "Rumble";
	r.save(os);
	o.close();
	
	std::ifstream i = std::ifstream("foobar.dat", std::ios_base::binary);
	std::istream* is = &i;
	auto objs = ResultObject::load(is);
	auto new_r = objs["Rumble"];
	EXPECT_TRUE(new_r->losses == 1);
	EXPECT_TRUE(new_r->wins == 2);
	EXPECT_TRUE(new_r->streak == 1);
	EXPECT_TRUE(new_r->mode == "Rumble");
	EXPECT_TRUE(new_r->previous == BGT::Types::Result::Result_WIN);
	i.close();
	//std::remove("foobar.dat");
}

TEST(results, can_do_multiple)
{
	std::ofstream o = std::ofstream("foobar.dat", std::ios_base::binary);
	std::ostream* os = &o;
	
	auto r = ResultObject();
	r.lose();
	r.win();
	r.win();
	r.mode = "Rumble";
	r.save(os);

	r = ResultObject();
	r.lose();
	r.lose();
	r.lose();
	r.win();
	r.lose();
	r.lose();
	r.mode = "Hoops";
	r.save(os);
	o.close();
	//EXPECT_TRUE(false) << o;
	std::ifstream i = std::ifstream("foobar.dat", std::ios_base::binary);
	std::istream* is = &i;
	auto objs = ResultObject::load(is);
	auto new_r = objs["Rumble"];
	EXPECT_TRUE(new_r->losses == 1);
	EXPECT_TRUE(new_r->wins == 2);
	EXPECT_TRUE(new_r->streak == 1);
	EXPECT_TRUE(new_r->mode == "Rumble");
	EXPECT_TRUE(new_r->previous == BGT::Types::Result::Result_WIN);

	new_r = objs["Hoops"];
	EXPECT_TRUE(new_r->losses == 5);
	EXPECT_TRUE(new_r->wins == 1);
	EXPECT_TRUE(new_r->streak == 1);
	EXPECT_TRUE(new_r->mode == "Hoops");
	EXPECT_TRUE(new_r->previous == BGT::Types::Result::Result_LOSS);

}