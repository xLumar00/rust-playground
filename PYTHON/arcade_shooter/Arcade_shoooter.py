import pygame
import os
import random
pygame.font.init()


WIDTH, HEIGHT = 1920,1080
window = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Arcade Shooter")
Icon = pygame.image.load(
    os.path.join("game_assets","icon.png"))
pygame.display.set_icon(Icon)

Spaceship_Width,Spaceship_Height = 100, 90
Alienship_Width,Alienship_Height = 500, 450
Bullet_Width, Bullet_Height = 6,16

Background  = pygame.image.load(
    os.path.join("game_assets","SpaceBG.jpg"))

Alienship = pygame.image.load(
    os.path.join("game_assets","Alienship.png"))
Alienship = pygame.transform.scale(Alienship,(Alienship_Width,Alienship_Height))
Alienship = pygame.transform.rotate(Alienship, 180)

Spaceship_100 = pygame.image.load(
    os.path.join("game_assets","Spaceship100.png"))
Spaceship_100 = pygame.transform.scale(Spaceship_100,(Spaceship_Width,Spaceship_Height))

Spaceship_75 = pygame.image.load(
    os.path.join("game_assets","Spaceship75.png"))
Spaceship_75 = pygame.transform.scale(Spaceship_75,(Spaceship_Width,Spaceship_Height))

Spaceship_50 = pygame.image.load(
    os.path.join("game_assets","Spaceship50.png"))
Spaceship_50 = pygame.transform.scale(Spaceship_50,(Spaceship_Width,Spaceship_Height))

Spaceship_25 = pygame.image.load(
    os.path.join("game_assets","Spaceship25.png"))
Spaceship_25 = pygame.transform.scale(Spaceship_25,(Spaceship_Width,Spaceship_Height))

# YOU_LOSE = pygame.image.load(
#     os.path.join("game_assets","YOU_LOSE.jpg"))
# YOU_LOSE = pygame.transform.scale(YOU_LOSE,(1920,1080))

my_font = pygame.font.SysFont("Comic Sans",150)
YOU_LOSE = my_font.render('YOU LOSE!', False, (255, 255, 255))


Spaceship = Spaceship_100


#White = (255, 255 ,255)
Yellow = (255, 255, 0)
FPS = 180
VEL = 10
BULLET_VEL = 10
Player_Bullets = []
Enemy_Bullets_1 = []
Enemy_Bullets_2 = []
Enemy_Bullets_3 = []

Health_levels = [Spaceship_25,Spaceship_50,Spaceship_75]
Player_Bullet_start = 0
Enemy_Bullet_start = 0
Player_hit_start = 0
Enemy_hit_start = 0
HP = 4
period = 1000
direction = True
start = pygame.time.get_ticks()
you_lose = False

Player = pygame.Rect(
        WIDTH//2 - Spaceship_Width//2, HEIGHT-Spaceship_Height, Spaceship_Width, Spaceship_Height)
Enemy = pygame.Rect(
        WIDTH//2 - Alienship_Width//2, 20, Alienship_Width, Alienship_Height)



#________________________________________________________________________________________________________
def draw_window(Player_Bullets, Enemy_Bullets_1, Enemy_Bullets_2, Enemy_Bullets_3):       #vykreslenie
    #window.fill(White) - mozes iba farbu
    window.blit(Background,(0,0))
    window.blit(Spaceship,(Player.x, Player.y))
    window.blit(Alienship,(Enemy.x, Enemy.y))

    bullet_draw(Player_Bullets)
    bullet_draw(Enemy_Bullets_1)
    bullet_draw(Enemy_Bullets_2)
    bullet_draw(Enemy_Bullets_3)
    

    pygame.display.update()
#________________________________________________________________________________________________________
def player_movement(Player, keys_pressed):
        if keys_pressed[pygame.K_a] and Player.x - VEL>0 :    #Dolava
            Player.x -= VEL
        if keys_pressed[pygame.K_d] and (Player.x + Spaceship_Width) < WIDTH :    #Doprava
            Player.x += VEL
        if keys_pressed[pygame.K_w] and Player.y - VEL> HEIGHT//2+Spaceship_Height :    #Hore
            Player.y -= VEL
        if keys_pressed[pygame.K_s] and (Player.y + Spaceship_Height) < HEIGHT :    #Dole
            Player.y += VEL 

def enemy_movement(Enemy,Player):
    global direction
    global start
    global period
    if Enemy.x + Alienship_Width//2 > Player.x + Spaceship_Width//2:
        direction = False
    elif Enemy.x + Alienship_Width//2 < Player.x + Spaceship_Width//2:
        direction = True
    # direction = bool(random.randint(0,1))
    period = random.randrange(500,1500)
    start = pygame.time.get_ticks()           
#______________________________________________________________________________________________________________________________
def bullet_movement(player_bool,Bullets):
    if player_bool:
    
        bullet_velocity = -BULLET_VEL
        for Bullet in Bullets:
            if Bullet.y > 0 :
                Bullet.y += bullet_velocity
            else:
                Bullets.remove(Bullet)
    else:
        bullet_velocity = BULLET_VEL/2
        for Bullet in Bullets:
            if Bullet.y < HEIGHT :
                Bullet.y += bullet_velocity
            else:
                Bullets.remove(Bullet)

def bullet_store_player(Player_Bullets):
    Bullet = pygame.Rect(
        Player.x + Spaceship_Width//2 - Bullet_Width//2 ,Player.y - 10,Bullet_Width,Bullet_Height)  
    Player_Bullets.append(Bullet)

def bullet_store_enemy(Enemy_Bullets_1,Enemy_Bullets_2,Enemy_Bullets_3):
    Bullet_1 = pygame.Rect(
        Enemy.x + Alienship_Width//2 - Bullet_Width//2 ,Enemy.y + Alienship_Height - 80,Bullet_Width,Bullet_Height)
    Enemy_Bullets_1.append(Bullet_1)
    Bullet_2 = pygame.Rect(
        Enemy.x + Alienship_Width//3 - Bullet_Width//2 + 10 ,Enemy.y + Alienship_Height -140 ,Bullet_Width,Bullet_Height)
    Enemy_Bullets_2.append(Bullet_2)
    Bullet_3 = pygame.Rect(
        Enemy.x + Alienship_Width//3*2 - Bullet_Width//2 - 10 ,Enemy.y + Alienship_Height - 140 ,Bullet_Width,Bullet_Height)
    Enemy_Bullets_3.append(Bullet_3)

def bullet_draw(Bullets):
    for Bullet in Bullets:
        pygame.draw.rect(window,Yellow,Bullet)
#______________________________________________________________________________________________________________________________

def player_hit(Bullets):
    global Player_hit_start
    for Bullet in Bullets:
        if Player.colliderect(Bullet) and pygame.time.get_ticks()-Player_hit_start > 400:
            health_points()
            Bullets.remove(Bullet)
            Player_hit_start = pygame.time.get_ticks()

def health_points():
    global Spaceship
    global HP
    global you_lose
    HP -=1
    keys_pressed = pygame.key.get_pressed()
    if HP == 0:
            you_lose = True
    else:
        for level in Health_levels:
            Spaceship = Health_levels[HP-1]





#________________________________________________________________________________________________________
def main():
    fps = pygame.time.Clock()
    run = True
    global Player_Bullet_start
    global Enemy_Bullet_start
    global period
    global start
    global you_lose

    while run:
        fps.tick(FPS)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False
        #_________________________________________      Tlacitka
        keys_pressed = pygame.key.get_pressed()
        
        if keys_pressed[pygame.K_ESCAPE]:   #Esc
            run = False
        if keys_pressed[pygame.K_p]:
            health_points()
        
        if keys_pressed[pygame.K_SPACE] and (pygame.time.get_ticks() - Player_Bullet_start) > 400:  #Medzernik 
            bullet_store_player(Player_Bullets)
            Player_Bullet_start = pygame.time.get_ticks()
            
        #_________________________________________      Ovladac





        #_________________________________________

        
        
        if (pygame.time.get_ticks()-start) < period:
            if direction == True and (Enemy.x + Alienship_Width//5 + Alienship_Width//2) <= WIDTH:
                Enemy.x += VEL/3
            if direction == False and (Enemy.x - Alienship_Width//5 + Alienship_Width//2) >= 0:
                Enemy.x -= VEL/3
        else:
            enemy_movement(Enemy,Player)
        if (pygame.time.get_ticks() - Enemy_Bullet_start) > random.randrange(500,5000):
            bullet_store_enemy(Enemy_Bullets_1,Enemy_Bullets_2,Enemy_Bullets_3)
            Enemy_Bullet_start = pygame.time.get_ticks()

        #_________________________________________
        player_movement(Player,keys_pressed)
        draw_window(Player_Bullets, Enemy_Bullets_1, Enemy_Bullets_2, Enemy_Bullets_3)
        
        bullet_movement(True,Player_Bullets)
        bullet_movement(False,Enemy_Bullets_1)
        bullet_movement(False,Enemy_Bullets_2)
        bullet_movement(False,Enemy_Bullets_3)
        player_hit(Enemy_Bullets_1)
        player_hit(Enemy_Bullets_2)
        player_hit(Enemy_Bullets_3)
        pygame.display.update()
        #_____________________________________________________
        
        while you_lose:
            window.blit(YOU_LOSE,(WIDTH//2-75,HEIGHT//2))
            pygame.display.update()
                
            for event in pygame.event.get():
                if event.type == pygame.KEYDOWN  and event.key == pygame.K_ESCAPE:
                    you_lose = False
                    run = False

    pygame.quit()

#_____________________________________________________
if __name__ == "__main__":
    main()
#main sa spusti len ak je otvoreny cez tento modul,
#  ak ho importnes nespusti sa automaticky


