<div class="row">
  <div class="col-lg-12">
    <div class="panel panel-info">
      <div class="panel-heading">
        <i class="fa fa-bitbucket fa-fw"></i> 本池捐赠者
      </div>
      <div class="panel-body table-responsive">
      <table class="table table-striped table-bordered table-hover {if $DONORS}datatable{/if}">
        <thead>
          <tr>
            <th>用户名</th>
            <th>%</th>
            <th>{$GLOBAL.config.currency} 总数</th>
          </tr>
        </thead>
        <tbody>
{section name=donor loop=$DONORS}
          <tr>
            <td>{if $DONORS[donor].is_anonymous|default:"0" == 1 && $GLOBAL.userdata.is_admin|default:"0" == 0}anonymous{else}{$DONORS[donor].username}{/if}</td>
            <td>{$DONORS[donor].donate_percent}</td>
            <td>{$DONORS[donor].donation|number_format:"2"}</td>
          </tr>
{sectionelse}
          <tr>
            <td colspan="3">还没有捐款信息,请耐心等待!
</td>
          </tr>
{/section}
        </tbody>
        </table>
      </div>
    </div>
  </div>
</div>
