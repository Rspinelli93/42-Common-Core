/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 22:32:11 by rick              #+#    #+#             */
/*   Updated: 2025/11/16 19:17:15 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"




/* A signal handler can have any name, but it must return void and accept a single int parameter, representing the signal number.

To trigger the signal handler when the signal has occurred, we use signal() function that is provided by <signal.h> header file.

Syntax:

signal(type, signalHandler);


void singalHandler(int sig)  { 
    printf("Caught signal %d\n", sig);
    exit(sig);
} 
  
int main()  { 
    signal(SIGINT, singalHandler); 
    while (1){
        printf("Hello World!\n");
    }
    return 0; 
}
 */