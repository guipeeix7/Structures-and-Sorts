/**
 * OBJECTIVE:
 * User needs to conquer the max ammount of area in a infinite matrix given a finite time (rounds), witch has a limit in number of actions
 * 
 * 1 - user start with aleatory eadzin position in a infinity matrix  
 * 2 - each edazin only can search one place by turn (loop)
 *     2A - Check if edazin isnt in map borders if not conquer the place
 *     2B - 
 * 3 - Only one domination is possible for rouns (single decision)
 *  
 * 
 * BEGIN:
 * L - Linha 
 * C - Coluna
 * P - Pontos (points that the edazin begin)
 * T - Turnos
 * 
 * TURNS:
 * sondar L C
 * dominar L C 
 * endturn
 * 
 * RESPONSES:
 * for sondar we receive 1 line with the points
 * for domination we receive the number of points earneds in domination
 * 
 * HINTS:
 * 1 - As said i can use a hash table to save the 'matrix'
 * 2 - Use freaking priority queue to save the points and position of them
 * 
 * OBSERVATIONS: 
 * Mojinho class
 * Map class
 * to receive arbitro data i use scanf
 * to send arbitro information i use printf 
 * 
*/