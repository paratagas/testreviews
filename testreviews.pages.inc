<?php

/**
 * @file
 * Contains testreviews pages functions.
 */
	
/**
 * Builds reviews form.
 */
function testreviews_page_form($form, $form_state) {
    $form = array();
    
    $form['title'] = array(
        '#type' => 'textfield',
        '#title' => t('Enter title'),
        '#size' => 20,
    );
    
    $form['category'] = array(
        '#type' => 'select',
        '#title' => t('Select category'),
        '#options' => array(
             'Public fiction' => 'Public fiction',
             'Science fantasy' => 'Science fantasy',
             'Detective story' => 'Detective story', 
             'Womens romance' => 'Womens romance'
        ),
    );
    
    $form['actuality'] = array(
        '#type' => 'radios',
        '#title' => t('Choose actuality'),
        '#options' => array(
            'Actual' => t('Actual'),
            'Archive' => t('Archive')
        ),
        '#default_value' => variable_get('actuality', 'Actual')
    );
    
    $form['published'] = array(
        '#type' => 'checkbox',
        '#title' => t('Publicate'),
        '#default_value' => 1
    );
    
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Save data'),
    );
    
    return $form;
}

/**
 * Builds review view.
 */
function testreviews_view_review() {
    $id = $_GET['id'];
    $review = testreviews_create_review_data($id);
    $content = t("Unable to find review information.");
    
    if($review){
        if($review[0][4] == '1'){
            $published = "Yes";
        }else{
            $published = "No";
        }
    
        $content = "<h2>Review information</h2>";
        $content .= "Id: {$review[0][0]}<br/>";
        $content .= "Title: {$review[0][1]}<br/>";
        $content .= "Category: {$review[0][2]}<br/>";
        $content .= "Actuality: {$review[0][3]}<br/>";
        $content .= "Published: $published<br/>";
    }
    
    return $content;
}

/**
 * Creates review data for testreviews_view_review()
 */
function testreviews_create_review_data($id) {
    $query = db_select('testreviews', 'tr')
      ->fields('tr')
      ->condition('id', $id)
      ->execute();
    
    $rows = false;
    
    while($value = $query->fetchAssoc())
    {
        $rows[] = array(
            $value['id'],
            $value['title'],
            $value['category'],
            $value['actuality'],
            $value['published']
        );
    }
    
    // если отзыв есть - возвращаем его, иначе - false
    return $rows;
}