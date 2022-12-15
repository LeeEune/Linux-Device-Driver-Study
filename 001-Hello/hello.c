/**
 * @file    hello.c
 * @author  Akshat Sinha & Eunhye Lee
 * @date    15 Dec 2022
 * @version 0.2
 * @brief  An introductory "Hello World!" loadable kernel
 *  module (LKM) that can display a message in the /var/log/kern.log
 *  file when the module is loaded and removed. The module can accept
 *  an argument when it is loaded -- the name, which appears in the
 *  kernel log files.
*/
#include <linux/module.h>     /* Needed by all modules */
#include <linux/kernel.h>     /* Needed for KERN_INFO */
#include <linux/init.h>       /* Needed for the macros */

///< The license type -- this affects runtime behavior
MODULE_LICENSE("GPL"); 
///< The author -- visible when you use modinfo
MODULE_AUTHOR("Eunhye Lee");
///< The description -- see modinfo
MODULE_DESCRIPTION("A simple Hello world LKM!");
///< The version of the module
MODULE_VERSION("0.2");
/*
sudo insmod hello.ko
sudo dmesg 
sudo rmmod hello.ko
*/

static int __init hello_start(void)
{
    printk(KERN_ALERT "Loading hello module...\n");
    printk(KERN_INFO "Hello world\n");
    pr_alert("pr_alert\n");
    pr_crit("pr_crit\n");
    pr_err("pr_err\n");
    pr_warn("pr_warning\n");
    pr_notice("pr_notice\n");
    pr_info("pr_notice\n");
    pr_debug("pr_debug\n");
    printk(KERN_DEBUG "debug\n");
    return 0;
}

static void __exit hello_end(void)
{
    printk(KERN_INFO "Goodbye Ms.\n");
    printk(KERN_DEBUG "debug\n");
}

module_init(hello_start);
module_exit(hello_end);
