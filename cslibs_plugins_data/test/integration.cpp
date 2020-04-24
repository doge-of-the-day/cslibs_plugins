#include <gtest/gtest.h>

#include <ros/ros.h>
#include <cslibs_plugins/plugin_loader.hpp>

#include <cslibs_plugins_data/data_provider.hpp>
#include <cslibs_math_ros/tf/tf_listener.hpp>

using data_provider_t = cslibs_plugins_data::DataProvider;
using tf_listener_t   = cslibs_math_ros::tf::TFListener;

TEST( Test_cslibs_plugins_data, testFindNames)
{
    ros::NodeHandle nh{"~"};

    const std::string package_name = "cslibs_plugins_data";

    cslibs_plugins::PluginManager<data_provider_t> manager(data_provider_t::Type(), package_name);
    manager.load();
    EXPECT_TRUE(manager.pluginsLoaded());

    std::vector<std::string> class_names = {
        "cslibs_plugins_data::LaserProvider",
        "cslibs_plugins_data::LaserProvider_d",
        "cslibs_plugins_data::LaserProvider_f",
        "cslibs_plugins_data::Pointcloud3dProvider",
        "cslibs_plugins_data::Pointcloud3dProvider_d",
        "cslibs_plugins_data::Pointcloud3dProvider_f",
        "cslibs_plugins_data::Odometry2DProvider",
        "cslibs_plugins_data::Odometry2DProvider_d",
        "cslibs_plugins_data::Odometry2DProvider_f",
        "cslibs_plugins_data::Odometry2DProviderTF",
        "cslibs_plugins_data::Odometry2DProviderTF_d",
        "cslibs_plugins_data::Odometry2DProviderTF_f"
    };

    for(const auto &class_name : class_names) {
        auto constructor = manager.getConstructor(class_name);
        data_provider_t::Ptr plugin;
        if(constructor) {
            plugin = constructor();
        } else {
            std::cerr << class_name << std::endl;
        }
        EXPECT_TRUE(plugin);
    }
}



TEST( Test_cslibs_plugins_data, testLoadLaserProvider)
{
    EXPECT_TRUE(true);
}

TEST( Test_cslibs_plugins_data, testLoadLaserProvider_d)
{
    EXPECT_TRUE(true);
}

TEST( Test_cslibs_plugins_data, testLoadLaserProvider_f)
{
    EXPECT_TRUE(true);
}

TEST( Test_cslibs_plugins_data, testLoadOdometry2DProviderTF)
{
    EXPECT_TRUE(true);
}

TEST( Test_cslibs_plugins_data, testLoadLaserOdometry2DProviderTF_d)
{
    EXPECT_TRUE(true);
}

TEST( Test_cslibs_plugins_data, testLoadOdometry2DProviderTF_f)
{
    EXPECT_TRUE(true);
}

TEST( Test_cslibs_plugins_data, testLoadOdometry2DProvider)
{
    EXPECT_TRUE(true);
}

TEST( Test_cslibs_plugins_data, testLoadLaserOdometry2DProvider_d)
{
    EXPECT_TRUE(true);
}

TEST( Test_cslibs_plugins_data, testLoadOdometry2DProvider_f)
{
    EXPECT_TRUE(true);
}

TEST( Test_cslibs_plugins_data, testLoadPointcloud3dProvider)
{
    EXPECT_TRUE(true);
}

TEST( Test_cslibs_plugins_data, testLoadLaserPointcloud3dProvider_d)
{
    EXPECT_TRUE(true);
}

TEST( Test_cslibs_plugins_data, testLoadPointcloud3dProvider_f)
{
    EXPECT_TRUE(true);
}


int main(int argc, char *argv[])
{

    ros::init(argc, argv, "cslibs_plugins_data_integration_test");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
